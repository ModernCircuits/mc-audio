# SPDX-License-Identifier: BSL-1.0

import re
import os

from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain
from conan.tools.files import copy, load

required_conan_version = ">=1.50.0"


class ModernCircuitsAudio(ConanFile):
    name = "mc-audio"
    url = "https://github.com/ModernCircuits/mc-audio"
    description = "Audio DSP Library"
    license = "BSL-1.0"

    settings = "os", "compiler", "build_type", "arch"

    requires = ["mc-core/0.11.0@modern-circuits/stable"]

    @property
    def _build_all(self):
        return bool(self.conf["user.build:all"])

    def set_version(self):
        path = os.path.join(self.recipe_folder, "src/CMakeLists.txt")
        content = load(self, path)
        regex = r"project\([^\)]+VERSION (\d+\.\d+\.\d+)[^\)]*\)"
        ver = re.search(regex, content).group(1)
        self.version = ver.strip()

    def build_requirements(self):
        if self._build_all:
            self.test_requires("catch2/3.1.0")

    def export_sources(self):
        self.copy("CMakeLists.txt")
        self.copy("src/*")
        self.copy("examples/*")
        self.copy("cmake/*")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure(build_script_folder=None if self._build_all else "src")
        cmake.build()
        if self._build_all:
            cmake.test()

    def package(self):
        copy(
            conanfile=self,
            pattern="LICENSE.txt",
            src=self.source_folder,
            dst=os.path.join(self.package_folder, "licenses"),
        )

        copy(
            conanfile=self,
            pattern="*.hpp",
            src=os.path.join(self.source_folder, "src"),
            dst=os.path.join(self.package_folder, "include"),
        )

        copy(
            conanfile=self,
            pattern="*.cpp",
            src=os.path.join(self.source_folder, "src"),
            dst=os.path.join(self.package_folder, "include"),
        )

        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.names["cmake_find_package"] = "mc-audio"
        self.cpp_info.names["cmake_find_package_multi"] = "mc-audio"
        self.cpp_info.names["pkg_config"] = "mc-audio"
        self.cpp_info.set_property("cmake_target_name", "mc::audio")
