import os
import pathlib

# skbuild = python setuptools with Cmake support
from skbuild import setup

setup(
    name='tinyusdz',
    version='0.8.0rc1',
    author='Light Transport Entertainment Inc.',
    author_email='lighttransport.eth@mail3.me',
    package_dir={'tinyusdz': 'python'}, # Use `python` folder 
    cmake_args=['-DTINYUSDZ_WITH_PYTHON=1', '-DTINYUSDZ_BUILD_EXAMPLES=Off', '-DTINYUSDZ_BUILD_TESTS=Off', '-DTINYUSDZ_WITH_TOOL_USDA_PARSER=Off', '-DTINYUSDZ_WITH_TOOL_USDC_PARSER=Off'],
    long_description=open("./python/README.md", 'r').read(),
    long_description_content_type='text/markdown',
    license='MIT',
)
