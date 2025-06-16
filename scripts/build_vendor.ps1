$ErrorActionPreference = "Stop"

$build_type = "Debug"
$generator = "Ninja"
$c_compiler = "cl"
$cxx_compiler = "cl"
$source_path = "$PSScriptRoot\..\vendor"
$build_path = "$PSScriptRoot\..\build\vendor"
$install_path = "$PSScriptRoot\..\vendor\installed"

cmake -DCMAKE_BUILD_TYPE="${build_type}" `
    -DCMAKE_INSTALL_PREFIX="${install_path}" `
    -DCMAKE_C_COMPILER="${c_compiler}" `
    -DCMAKE_CXX_COMPILER="${cxx_compiler}" `
    -S"${source_path}" `
    -B"${build_path}" `
    -G"${generator}"
if ($LastExitCode -ne 0)
{
    exit $LastExitCode
}

cmake --build `
    "${build_path}" `
    --config "${build_type}"
if ($LastExitCode -ne 0)
{
    exit $LastExitCode
}

cmake --install `
    "${build_path}" `
    --config "${build_type}" `
    --prefix "${install_path}"
if ($LastExitCode -ne 0)
{
    exit $LastExitCode
}
