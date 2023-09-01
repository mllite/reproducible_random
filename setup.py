
from glob import glob
from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

# cpp_args = ['-std=c++11']

__version__ = "0.0.1rc0"

ext_modules = [
    Pybind11Extension(
        "reproducible_random", ["reproducible_random.cpp"]),
]

print(ext_modules)

setup(
    name="reproducible_random",
    version=__version__,
    author="Antoine CARME",
    author_email="antoine.carme@outlook.com",
    url="https://github.com/XXXXXXX",
    description="A reproducible random number generator module using pybind11",
    long_description="",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    python_requires=">=3.11",
)
