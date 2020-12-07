-- premake5.lua

-- This function includes GLFW's header files
function includeGLFW()
    includedirs "external/windows/glfw/include"
end	

-- This function links statically against GLFW
function linkGLFW()
    libdirs "external/windows/glfw/lib"
    
    -- Our static lib should not link against GLFW
    filter "kind:not StaticLib"
        links "glfw3"
    filter {}
end


function linkVulkan()
    includedirs("$(VULKAN_SDK)/include")
    
    links("$(VULKAN_SDK)/lib/vulkan-1.lib")
end

workspace "LOADengine"
    configurations { "Debug", "Release" }
    platforms {"x86_64"}

project "LOADengine"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    location ("gen")

    includedirs "external/glm"
    includeGLFW()
    linkGLFW()

    linkVulkan()
    
    files { "src/**.h", "src/**.cpp" }
    vpaths {
        ["Headers"] = { "src/**.h", "src/**.hpp" },
        ["Sources"] = { "src/**.c", "src/**.cpp" },
    }

    

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "Full"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"