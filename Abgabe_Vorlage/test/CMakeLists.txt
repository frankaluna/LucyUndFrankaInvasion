enable_testing()

set(ViewSources
    ${CMAKE_SOURCE_DIR}/src/view/Layer.cpp
    )
# Model
set(ModelSources
    ${CMAKE_CURRENT_SOURCE_DIR}/model/Alien.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/model/Laser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/model/Player.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/model/Shield.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/model/Spaceship.cpp
)
# Controller
set(ControlSources
    ${CMAKE_CURRENT_SOURCE_DIR}/control/Game.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/control/SpaceshipControl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/control/AlienControl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/control/OverlayControl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/control/PlayerControl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/control/ShieldControl.cpp
    )

set(TestSources
    ${CMAKE_CURRENT_SOURCE_DIR}/GameTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AliencontrolTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AlienTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OverlayControlTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ShieldControlTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ShieldTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/LaserTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerControlTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SpaceshipTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SpaceshipControlTest.cpp

    )

add_executable(Test
    ${ModelSources}
    ${ControlSources}
    ${ViewSources}
    ${TestSources}
    )
