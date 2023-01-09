#ifndef NIANNIAN_ALLSCENES_HPP
#define NIANNIAN_ALLSCENES_HPP



namespace AllScenes
{
    enum e_Scenes
    {
        Empty,
        Splash,
        MainMenu,
        GameSceneLevelOne,
    };

    static const e_Scenes All[] = { Splash,MainMenu, GameSceneLevelOne };
}

#endif //NIANNIAN_ALLSCENES_HPP
