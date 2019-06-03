#include "SceneManager.h"

SceneManager::SceneManager() {
    if(scenes.size() < 1) {
        scenes.push_back(new Scene);
    }
    currentScene = scenes[0];
}

SceneManager::~SceneManager() {
    for(Scene* s : scenes) {
        delete s;
    }
}

Scene* const SceneManager::getCurrentScene() const {
    return currentScene;
}

void SceneManager::changeScene(int sceneIndex) {
    if(sceneIndex < 0) {
        sceneIndex = 0;
    }
    else if(sceneIndex >= scenes.size()) {
        sceneIndex = scenes.size() - 1;
    }

    currentScene = scenes[sceneIndex];
}