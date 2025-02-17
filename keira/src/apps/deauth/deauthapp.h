#pragma once

#include "app.h"
#include <lilka.h>
class deauthapp : public App {
public:
    deauthapp();
private:
    void run() override;
    void controlmenu();
};