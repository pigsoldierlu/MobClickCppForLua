
#include "MobClickCppForLua.h"

USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    #include "MobClickCpp.h"
    using namespace umeng;



eventDict* str2Map(const char* pStr) {
    if (NULL == pStr) {
        return NULL;
    }
    int nStrLen = strlen(pStr);
    if (0 == nStrLen) {
        return NULL;
    }
    
    eventDict *pDict = new eventDict();
    
    char* pSearchStr = (char*)pStr;
    char* pFoundStr = NULL;
    while (true) {
        //search key
        pFoundStr = strchr(pSearchStr, ',');
        if (NULL == pFoundStr) {
            break;
        }
        string key;
        key.assign(pSearchStr, pFoundStr - pSearchStr);
        
        //search value
        pSearchStr = pFoundStr + 1;
        pFoundStr = strchr(pSearchStr, '|');
        if (NULL == pFoundStr) {
            //think as it's last one
            pFoundStr = (char*)(pStr + nStrLen);
        }
        string val;
        val.assign(pSearchStr, pFoundStr - pSearchStr);
        
        pDict->insert(pair<string, string>(key, val));
        
        pSearchStr = pFoundStr + 1;
        if (pSearchStr >= pStr + nStrLen) {
            break;
        }
    }
    
    return pDict;
}


#endif



void MobClickCppForLua::installAndStart(const char * appKey, const char * channelId) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    umeng::MobClickCppDelegate* delegete = new umeng::MobClickCppDelegate;
    cocos2d::CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(umeng::MobClickCppDelegate::mainloop), (delegete), 0, false);
    
    MobClickCpp::startWithAppkey(appKey, channelId);
#endif
}


void MobClickCppForLua::setLogEnabled(bool value) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::setLogEnabled(value);
#endif
}


void MobClickCppForLua::setProxy(const char* host, int port) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::setProxy(host, port);
#endif
}


void MobClickCppForLua::setSessionIdleLimit(int seconds) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::setSessionIdleLimit(seconds);
#endif
}


void MobClickCppForLua::startWithAppkey(const char * appKey, const char * channelId) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::startWithAppkey(appKey, channelId);
#endif
}


void MobClickCppForLua::applicationDidEnterBackground() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::applicationDidEnterBackground();
#endif
}


void MobClickCppForLua::applicationWillEnterForeground() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::applicationWillEnterForeground();
#endif
}


void MobClickCppForLua::end() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::end();
#endif
}

void MobClickCppForLua::mainloop(float dt) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::mainloop(dt);
#endif
}


void MobClickCppForLua::event(const char * eventId, const char * label) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::event(eventId, label);
#endif
    
}

void MobClickCppForLua::eventCustom(const char * eventId, const char * attributes, int counter) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    eventDict *pDict = str2Map(attributes);
    MobClickCpp::event(eventId, pDict, counter);
    delete pDict;
#endif
}

void MobClickCppForLua::beginLogPageView(const char *pageName) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::beginLogPageView(pageName);
#endif
}

void MobClickCppForLua::endLogPageView(const char *pageName) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::endLogPageView(pageName);
#endif
}


void MobClickCppForLua::updateOnlineConfig(MobClickOnlineConfigUpdateDelegate* pDelegate, void *pUserData) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::updateOnlineConfig(pDelegate, pUserData);
#endif
}


const char* MobClickCppForLua::getConfigParam(const char * key) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    string val = MobClickCpp::getConfigParam(key);
    return val.c_str();
#else
	return "";
#endif
}


void MobClickCppForLua::setUserLevel(const char *level) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::setUserLevel(level);
#endif
}

void MobClickCppForLua::setUserInfo(const char * userId, int sex, int age, const char * platform) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::setUserInfo(userId, (MobClickCpp::Sex)sex, age, platform);
#endif
}

void MobClickCppForLua::startLevel(const char * level) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::startLevel(level);
#endif
}

void MobClickCppForLua::finishLevel(const char * level) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::finishLevel(level);
#endif
}

void MobClickCppForLua::failLevel(const char * level) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::failLevel(level);
#endif
}

void MobClickCppForLua::pay(double cash, int source, double coin) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::pay(cash, source, coin);
#endif
}

void MobClickCppForLua::pay(double cash, int source, const char * item, int amount, double price) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::pay(cash, source, item, amount, price);
#endif
}

void MobClickCppForLua::buy(const char *item, int amount, double price) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::buy(item, amount, price);
#endif
}

void MobClickCppForLua::use(const char * item, int amount, double price) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::use(item, amount, price);
#endif
}

void MobClickCppForLua::bonus(double coin, int source) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::bonus(coin, source);
#endif
}

void MobClickCppForLua::bonus(const char * item, int amount, double price, int source) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) || (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    MobClickCpp::bonus(item, amount, price, source);
#endif
}

