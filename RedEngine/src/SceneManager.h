#pragma once
#include "Scene.h"
#include <vector>

class SceneManager {
private:
    std::vector<Scene*> scenes;
    int currentSceneIndex;
public:
    SceneManager();
    ~SceneManager();

    Scene* const getCurrentScene() const;
    int addScene();
    void changeScene(int sceneIndex);
    void nextScene();
    void previousScene();
};