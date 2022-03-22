
#include "ui_manager.h"
#include "game_scene_manager.h"
#include "event_manager.h"

int main()
{
    // loading:
    // 单独的页面，在白屏状态最先加载，然后在ui_manager切换的时候显示，
    // load是先将资源预加载到queue<>load里面然后创建加载线程->加载->将状态返回render->加载结束后show

    UIManager           UIManager;
    GameSceneManager    GameSceneManager;
    event_manager       eventManager;

    UIManager.eventRegister(&eventManager);
    GameSceneManager.eventRegister(&eventManager);

    eventManager.eventEmit(GAME_GOTO_SCENE, GAME_1);
    eventManager.eventEmit(GAME_GOTO_SCENE, GAME_2);
    eventManager.eventEmit(GAME_GOTO_SCENE, GAME_1);
    eventManager.eventEmit(GAME_GOTO_SCENE, GAME_2);

    // eventManager.eventEmit(UI_NEXT);
    // eventManager.eventEmit(UI_NEXT);
    // eventManager.eventEmit(UI_NEXT);

    // eventManager.eventEmit(UI_BACKHOME);

    return 0;
}
