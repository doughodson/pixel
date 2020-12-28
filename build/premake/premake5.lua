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

--------------------------------------------------------------------------------
-- example applications
--------------------------------------------------------------------------------
PGEExamples = {
   "hello-world",
   "drawing-pixels",
   "user-input",
   "managing-time",
   "sprites",
   "collisions",
   "decals",
};

--------------------------------------------------------------------------------
-- example application project definition
--------------------------------------------------------------------------------
local function CreatePGEProject( projectName )
   project( projectName )
      kind("ConsoleApp")
      entrypoint("mainCRTStartup")
      location("../" .. _ACTION .. "/examples/%{prj.name}")
      debugdir("../../"..projectName)
      targetname(projectName)
      targetdir("../../"..projectName)
      files {
         "../../"..projectName.."/**.h*",
         "../../"..projectName.."/**.cpp",
      }
      includedirs { PGE_IncPath }
      defines { "_CONSOLE" }
end

workspace "examples"

   -- destination directory for generated solution/project files
   location ("../" .. _ACTION)

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

--------------------------------------------------------------------------------
-- create all example projects
--------------------------------------------------------------------------------
for index=1, #PGEExamples do
   CreatePGEProject( PGEExamples[index] );
end

