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
# View
set(ViewSources
    ${CMAKE_CURRENT_SOURCE_DIR}/view/Layer.cpp
    )

# add src code to target
add_executable(SpaceInvaders
        ${ModelSources}
        ${ControlSources}
        ${ViewSources}
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        )