# SPDX-License-Identifier: BSL-1.0

import re
import os

from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain
from conan.tools.files import copy, load

# TODO remove when `CONAN_RUN_TESTS` will be replaced with a `[conf]` variable
from conans.tools import get_env


class ModernCircuitsSTL(ConanFile):
    name = "mc-dsp"
    url = "https://github.com/ModernCircuits/mc-dsp"
    description = "Audio DSP Linrary"
    license = "BSL-1.0"

    settings = "os", "compiler", "build_type", "arch"

    requires = [
        "mc-core/0.3.3@modern-circuits/stable",
    ]

    @property
    def _run_tests(self):
        return get_env("CONAN_RUN_TESTS", False)

    def set_version(self):
        path = os.path.join(self.recipe_folder, "src/CMakeLists.txt")
        content = load(self, path)
        regex = r"project\([^\)]+VERSION (\d+\.\d+\.\d+)[^\)]*\)"
        ver = re.search(regex, content).group(1)
        self.version = ver.strip()

    def build_requirements(self):
        if self._run_tests:
            pass

    def export_sources(self):
        self.copy("CMakeLists.txt")
        self.copy("src/*")
        self.copy("examples/*")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure(build_script_folder=None if self._run_tests else "src")
        cmake.build()
        if self._run_tests:
            cmake.test()

    def package(self):
        copy(
            self,
            "LICENSE.txt",
            self.source_folder,
            os.path.join(self.package_folder, "licenses"),
        )
        cmake = CMake(self)
        cmake.install()
