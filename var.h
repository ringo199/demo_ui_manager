#ifndef __VAR_H__
#define __VAR_H__

enum e_scene_type
{
    LOADING = -2,
    UI_SCENE_NULL = -1,

    CHECK_MASTER_SERVER,
    LOGIN,
    CHECK_SLAVE_SERVER,
    CHECK_PLAYER,
    GAME,

    UI_COUNT
};

enum e_game_scene_type
{
    GAME_SCENE_NULL = -1,
    GAME_1,
    GAME_2,

    GAME_SCENE_COUNT
};

enum e_event_type
{
    UI_NEXT,
    UI_BACK,
    UI_BACKHOME,

    UI_BEGIN_LOADING,
    UI_END_LOADING,

    GAME_GOTO_SCENE,
};


#endif
