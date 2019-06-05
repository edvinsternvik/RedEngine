#include "SceneManager.h"

SceneManager::SceneManager() {
    if(scenes.size() < 1) {
        scenes.push_back(new Scene);
    }
    currentSceneIndex = 0;
}

SceneManager::~SceneManager() {
    for(Scene* s : scenes) {
        delete s;
    }
}

Scene* const SceneManager::getCurrentScene() const {
    return scenes[currentSceneIndex];
}

int SceneManager::addScene() {
    scenes.push_back(new Scene);

    return scenes.size() - 1;
}

void SceneManager::changeScene(int sceneIndex) {
    if(sceneIndex < 0) {
        sceneIndex = 0;
    }
    else if(sceneIndex >= scenes.size()) {
        sceneIndex = scenes.size() - 1;
    }

    currentSceneIndex = sceneIndex;
}

void SceneManager::nextScene() {
    currentSceneIndex += 1;

    if(currentSceneIndex >= scenes.size()) currentSceneIndex = 0;
}

void SceneManager::previousScene() {
    currentSceneIndex -= 1;

    if(currentSceneIndex < 0) currentSceneIndex = scenes.size() - 1;
}