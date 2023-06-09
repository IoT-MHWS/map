import os

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain
from conan.tools.cmake import cmake_layout, CMake
from conan.tools.files import copy


class map(ConanFile):
    name = "map"
    version = "1.0"

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"

    def source(self):
        pass

    def requirements(self):
        self.requires("grpc/1.50.1")
        self.requires("rapidjson/cci.20220822")
        self.test_requires("gtest/cci.20210126")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)

        if self.settings.build_type == "Debug":
            tc.cache_variables["BUILD_TESTING"] = True
            tc.cache_variables["ADD_CWS_MAP"] = True
            tc.cache_variables["ADD_PROTO"] = True
            tc.cache_variables["ADD_GRPC_SERVER"] = True

        tc.generate()

    def build(self):
        # copy everything from folder with different name
        cmake = CMake(self)
        cmake.configure()
        cmake.build(["--verbose"])
