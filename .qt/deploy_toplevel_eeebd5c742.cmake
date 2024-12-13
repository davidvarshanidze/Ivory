include(/Users/sasha/Ivory/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/toplevel-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_ALL_MODULES_FOUND_VIA_FIND_PACKAGE "Core;DBus;Gui;Widgets")

qt6_deploy_runtime_dependencies(
    EXECUTABLE toplevel.app
)
