//
//  GameModelData.h
//  SDLSkeleton
//
//  Created by James Folk on 2/22/20.
//

#ifndef GameModelData_hpp
#define GameModelData_hpp
//MLBJson::Dss data = nlohmann::json::parse(mlbJson);

#include "MLBJsonModel.h"
#include "ThreadPool.h"
#include "PubSub.h"

class GameModelData : public Publisher, public Subscriber {
    MLBJson::Dss mDssData;
    std::string mUrl;
    
    GameModelData(const GameModelData&)= delete;
    const GameModelData &operator=(const GameModelData&) = delete;
    
    // http://statsapi.mlb.com/api/v1/schedule?hydrate=game(content(editorial(recap))),decisions&date=2018-06-10&sportId=1
    static const std::string URLBase;

    GameModelData(const std::string url = "http://statsapi.mlb.com/api/v1/schedule?hydrate=game(content(editorial(recap))),decisions&date=2018-06-10&sportId=1");
public:
    ~GameModelData(){}
    
    /// Crate an instance to this class and kick off a background routine to download the json data, asynchrounsly.
    /// Once the json data is downloaded, new instances of the GameModelViewData objects will be created
    /// for each of the games for that day.
    /// @param time_str <#time_str description#>
    static GameModelData *generateGameModelData(struct tm time_str);
    
    /// Set the json text for this instance and notify the subscriber.
    /// @param json the json text.
    void setJson(char *json);
    
    /// get the url for this instance.
    const std::string &getUrl()const;
    
    /// get the data object for this instance.
    const MLBJson::Dss &getMLBData()const;
    
    /// This intance's publishing function.
    /// @param who userdata can be passed through the publisher's notify call.
    virtual void update(Publisher* who, void* userdata = 0);
};

#endif /* GameModelData_hpp */