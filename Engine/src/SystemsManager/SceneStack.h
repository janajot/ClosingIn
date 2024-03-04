//
// Created by Let'sBlend on 28/02/2024.
//

#ifndef CLOSING_SCENESTACK_H
#define CLOSING_SCENESTACK_H

class Scene;

class SceneStack
{
public:
    void PushScene(std::string&& name);
    void PopScene(std::string&& name);
    void PopAll();

    std::shared_ptr<Scene> GetScene(std::string&& name);
    std::vector<std::shared_ptr<Scene>>::iterator begin() { return scenePtrs.begin(); }
    std::vector<std::shared_ptr<Scene>>::iterator end() { return scenePtrs.end(); }

    std::vector<std::shared_ptr<Scene>> scenePtrs;
private:
};


#endif //CLOSING_SCENESTACK_H
