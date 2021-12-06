#ifndef PROCESSOR_H
#define PROCESSOR_H

class processor{
    /**
     * @brief defines behavior for each audio processor
     * 
     */
    virtual void process()=0;
};

#endif