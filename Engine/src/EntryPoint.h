//
// Created by Let'sBlend on 27/02/2024.
//

#ifndef APPLICATION_ENTRYPOINT_H
#define APPLICATION_ENTRYPOINT_H

#endif //APPLICATION_ENTRYPOINT_H


extern Engine* CreateApplication();

int main()
{
    auto app = CreateApplication();
    app->Run();
    delete app;
}