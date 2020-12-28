--
-- If premake command is not supplied an action (target compiler), exit!
--
-- Target of interest:
--     vs2017     (Visual Studio 2017)
--     vs2019     (Visual Studio 2019)

-- we must have an ide/compiler specified
if (_ACTION == nil) then
  return
end

--
-- directory locations
--
PIXEL_ROOT           = "../../"

--
-- set include paths
--
PGE_IncPath          = PIXEL_ROOT.."include"

print ("PIXEL Path:")
print ("  Include   : "..PGE_IncPath)

workspace "examples"

   -- destination directory for generated solution/project files
   location ("../" .. _ACTION)

   -- create console application by default
   kind "ConsoleApp"

   -- C++ code in all projects
   language "C++"

   --
   -- Build (solution) configuration options:
   --     Release        (Application linked to Multi-threaded DLL)
   --     Debug          (Application linked to Multi-threaded Debug DLL)
   --
   configurations { "Release", "Debug" }

   -- visual studio options and warnings
   -- /wd4351 (C4351 warning) - disable warning associated with array brace initialization
   -- /wd4996 (C4996 warning) - disable deprecated declarations
   -- /wd4005 (C4005 warning) - disable macro redefinition
   -- /wd4100 (C4100 warning) - disable unreferenced formal parameter
   -- /Oi - generate intrinsic functions
   disablewarnings { "4351",  "4996", "4005", "4100" }
   buildoptions { "/Oi" }

   -- common release configuration flags, symbols and libraries
   filter { "configurations:Release" }
      optimize "On"
      -- favor speed over size
      buildoptions { "/Ot" }
      defines { "WIN32", "NDEBUG" }

   -- common debug configuration flags, symbols and libraries
   filter { "configurations:Debug" }
      symbols "On"
      targetsuffix "_d"
      defines { "WIN32", "_DEBUG" }

---------------------------------------------
-- Projects
---------------------------------------------

project "hello-world"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "hello-world"
   targetdir "../../hello-world"
   debugdir "../../hello-world"
   files {
      "../../hello-world/**.h*",
      "../../hello-world/**.cpp",
   }
   includedirs { PGE_IncPath }
   defines { "_CONSOLE" }

project "drawing-pixels"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "drawing-pixels"
   targetdir "../../drawing-pixels"
   debugdir "../../drawing-pixels"
   files {
      "../../drawing-pixels/**.h*",
      "../../drawing-pixels/**.cpp",
   }
   includedirs { PGE_IncPath }
   defines { "_CONSOLE" }

project "user-input"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "user-input"
   targetdir "../../user-input"
   debugdir "../../user-input"
   files {
      "../../user-input/**.h*",
      "../../user-input/**.cpp",
   }
   includedirs { PGE_IncPath }
   defines { "_CONSOLE" }

project "managing-time"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "managing-time"
   targetdir "../../managing-time"
   debugdir "../../managing-time"
   files {
      "../../managing-time/**.h*",
      "../../managing-time/**.cpp",
   }
   includedirs { PGE_IncPath }
   defines { "_CONSOLE" }

project "sprites"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "sprites"
   targetdir "../../sprites"
   debugdir "../../sprites"
   files {
      "../../sprites/**.h*",
      "../../sprites/**.cpp",
   }
   includedirs { PGE_IncPath }
   defines { "_CONSOLE" }

project "collisions"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "collisions"
   targetdir "../../collisions"
   debugdir "../../collisions"
   files {
      "../../collisions/**.h*",
      "../../collisions/**.cpp",
   }
   includedirs { PGE_IncPath }
   defines { "_CONSOLE" }

project "decals"
   location ("../" .. _ACTION .. "/examples/%{prj.name}")
   targetname "decals"
   targetdir "../../decals"
   debugdir "../../decals"
   files {
      "../../decals/**.h*",
      "../../decals/**.cpp",
   }
   includedirs { PGE_IncPath }
   defines { "_CONSOLE" }
