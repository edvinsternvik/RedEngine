#pragma once
#include "Scene.h"
#include <vector>

class SceneManager {
private:
    std::vector<Scene*> scenes;
    Scene* currentScene;
public:
    SceneManager();
    ~SceneManager();

    Scene* const getCurrentScene() const;
    void changeScene(int sceneIndex);
};