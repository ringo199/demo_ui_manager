
#include "game_scene_manager.h"

GameSceneManager::GameSceneManager()
{
    this->_cur_game_scene_type = GAME_SCENE_NULL;
}

GameSceneManager::~GameSceneManager()
{
}

void GameSceneManager::gotoScene(void* ctx, e_game_scene_type type)
{
    GameSceneManager *context = (GameSceneManager*)ctx;
    if (context->_cur_game_scene_type != GAME_SCENE_NULL)
    {
        context->hideScene();
    }

    context->loadScene(type);
    context->showScene(type);
}

void GameSceneManager::eventRegister(event_manager* event_manager)
{
    this->_event_manager = event_manager;
    event_manager->eventRegister(GAME_GOTO_SCENE, (long)&this->gotoScene, this);
}

void GameSceneManager::loadScene(e_game_scene_type type)
{
    if (this->_sceneMap[type] != NULL) return;

    this->_event_manager->eventEmit(UI_BEGIN_LOADING);

    switch (type)
    {
    case GAME_1:
        this->_sceneMap[type] = new game_1;
        break;
    case GAME_2:
        this->_sceneMap[type] = new game_2;
        break;
    default:
        break;
    }

    this->_sceneMap[type]->init();
    this->_event_manager->eventEmit(UI_END_LOADING);
}

void GameSceneManager::showScene(e_game_scene_type type)
{
    this->_cur_game_scene_type = type;
    this->_sceneMap[type]->show();
}

void GameSceneManager::hideScene()
{
    this->_sceneMap[_cur_game_scene_type]->hide();
}
