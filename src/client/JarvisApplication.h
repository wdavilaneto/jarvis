//
// Created by walter on 16/09/15.
//

#ifndef JARVIS_JARVISAPPLICATION_H
#define JARVIS_JARVISAPPLICATION_H

#include "BaseApplication.h"

class JarvisApplication : public BaseApplication
{
public:

    JarvisApplication(void);
    virtual ~JarvisApplication(void);

protected:
    virtual void createScene();
};


#endif //JARVIS_JARVISAPPLICATION_H
