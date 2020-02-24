//
//  MLBJsonModel.h
//  SDLSkeleton
//
//  Created by James Folk on 2/21/20.
//

#ifndef MLBJsonModel_h
#define MLBJsonModel_h

//  Generated using: https://app.quicktype.io/

#pragma once

#include "nlohmann/json.hpp"

#include <optional>
#include <regex>
#include <stdexcept>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T> struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json &j, const std::shared_ptr<T> &opt) {
            if (!opt)
                j = nullptr;
            else
                j = *opt;
        }

        static std::shared_ptr<T> from_json(const json &j) {
            if (j.is_null())
                return std::unique_ptr<T>();
            else
                return std::unique_ptr<T>(new T(j.get<T>()));
        }
    };
} // namespace nlohmann
#endif

namespace MLBJson {
    using nlohmann::json;

    inline json get_untyped(const json &j, const char *property) {
            if (j.find(property) != j.end()) {
                return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json &j, std::string property) {
        return get_untyped(j, property.data());
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json &j,
                                           const char *property) {
            if (j.find(property) != j.end()) {
                return j.at(property).get<std::shared_ptr<T>>();
        }
        return std::shared_ptr<T>();
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json &j,
                                           std::string property) {
        return get_optional<T>(j, property.data());
    }

    enum class Source : int { MLB_COM };

    class ContributorElement {
      public:
        ContributorElement() = default;
        virtual ~ContributorElement() = default;

      private:
        std::string name;
        Source source;
        std::string tagline;
        std::string twitter;

      public:
        const std::string &getName() const { return name; }
        std::string &getMutableName() { return name; }
        void setName(const std::string &value) { this->name = value; }

        const Source &getSource() const { return source; }
        Source &getMutableSource() { return source; }
        void setSource(const Source &value) { this->source = value; }

        const std::string &getTagline() const { return tagline; }
        std::string &getMutableTagline() { return tagline; }
        void setTagline(const std::string &value) { this->tagline = value; }

        const std::string &getTwitter() const { return twitter; }
        std::string &getMutableTwitter() { return twitter; }
        void setTwitter(const std::string &value) { this->twitter = value; }
    };

    class AwayContributor {
      public:
        AwayContributor() = default;
        virtual ~AwayContributor() = default;

      private:
        std::vector<ContributorElement> contributors;
        Source source;
        std::string image;

      public:
        const std::vector<ContributorElement> &getContributors() const {
            return contributors;
        }
        std::vector<ContributorElement> &getMutableContributors() {
            return contributors;
        }
        void setContributors(const std::vector<ContributorElement> &value) {
            this->contributors = value;
        }

        const Source &getSource() const { return source; }
        Source &getMutableSource() { return source; }
        void setSource(const Source &value) { this->source = value; }

        const std::string &getImage() const { return image; }
        std::string &getMutableImage() { return image; }
        void setImage(const std::string &value) { this->image = value; }
    };

    enum class AspectRatio : int { EMPTY, THE_169, THE_43, THE_52, THE_6427 };

    class Cut {
      public:
        Cut() = default;
        virtual ~Cut() = default;

      private:
        AspectRatio aspectRatio;
        int64_t width;
        int64_t height;
        std::string src;
        std::string at2X;
        std::string at3X;

      public:
        const AspectRatio &getAspectRatio() const { return aspectRatio; }
        AspectRatio &getMutableAspectRatio() { return aspectRatio; }
        void setAspectRatio(const AspectRatio &value) {
            this->aspectRatio = value;
        }

        const int64_t &getWidth() const { return width; }
        int64_t &getMutableWidth() { return width; }
        void setWidth(const int64_t &value) { this->width = value; }

        const int64_t &getHeight() const { return height; }
        int64_t &getMutableHeight() { return height; }
        void setHeight(const int64_t &value) { this->height = value; }

        const std::string &getSrc() const { return src; }
        std::string &getMutableSrc() { return src; }
        void setSrc(const std::string &value) { this->src = value; }

        const std::string &getAt2X() const { return at2X; }
        std::string &getMutableAt2X() { return at2X; }
        void setAt2X(const std::string &value) { this->at2X = value; }

        const std::string &getAt3X() const { return at3X; }
        std::string &getMutableAt3X() { return at3X; }
        void setAt3X(const std::string &value) { this->at3X = value; }
    };

    class Image {
      public:
        Image() = default;
        virtual ~Image() = default;

      private:
        std::string title;
        std::string altText;
        std::vector<Cut> cuts;

      public:
        const std::string &getTitle() const { return title; }
        std::string &getMutableTitle() { return title; }
        void setTitle(const std::string &value) { this->title = value; }

        const std::string &getAltText() const { return altText; }
        std::string &getMutableAltText() { return altText; }
        void setAltText(const std::string &value) { this->altText = value; }

        const std::vector<Cut> &getCuts() const { return cuts; }
        std::vector<Cut> &getMutableCuts() { return cuts; }
        void setCuts(const std::vector<Cut> &value) { this->cuts = value; }
    };

    enum class TypeEnum : int {
        ACTIVE_BEATWRITERS,
        ACTIVE_COLUMNISTS,
        ALL_STAR,
        ARCHIVE_ELEMENT,
        AUTHFLOW,
        AWAY_TEAM_ID,
        BODY_PARAGRAPH_COUNT,
        BODY_WORD_COUNT,
        CALENDAR_EVENT_ID,
        CBSSPORTS_PLAYER_ID,
        CLOB_AUTO_TAG_SKIP_PLAYER_CARDS,
        CLOSED_CAPTIONS_LOCATION_TTML,
        CLOSED_CAPTIONS_LOCATION_VTT,
        COMBINED_MEDIA_STATE,
        CONTENT,
        EVENT_DATE,
        GAME_EVENTS_LOCATION_PLIST,
        GAME_ID,
        GAME_PK,
        HOME_TEAM_ID,
        INNING_INDEX_LOCATION_PLIST,
        INNING_INDEX_LOCATION_XML,
        LANGUAGE,
        MLBTAX,
        MMTAX,
        PLAYER_ID,
        RUN_SCORING_PLAYS_LOCATION_PLIST,
        SUBJECT,
        SV_ID,
        TEAM_FILE_CODE,
        TEAM_ID
    };

    class Keywords {
      public:
        Keywords() = default;
        virtual ~Keywords() = default;

      private:
        TypeEnum type;
        std::string value;
        std::string displayName;

      public:
        const TypeEnum &getType() const { return type; }
        TypeEnum &getMutableType() { return type; }
        void setType(const TypeEnum &value) { this->type = value; }

        const std::string &getValue() const { return value; }
        std::string &getMutableValue() { return value; }
        void setValue(const std::string &value) { this->value = value; }

        const std::string &getDisplayName() const { return displayName; }
        std::string &getMutableDisplayName() { return displayName; }
        void setDisplayName(const std::string &value) {
            this->displayName = value;
        }
    };

    class GameNotes {
      public:
        GameNotes() = default;
        virtual ~GameNotes() = default;

      private:
      public:
    };

    class Photo {
      public:
        Photo() = default;
        virtual ~Photo() = default;

      private:
        std::string title;
        std::string altText;
        std::map<std::string, Cut> cuts;

      public:
        const std::string &getTitle() const { return title; }
        std::string &getMutableTitle() { return title; }
        void setTitle(const std::string &value) { this->title = value; }

        const std::string &getAltText() const { return altText; }
        std::string &getMutableAltText() { return altText; }
        void setAltText(const std::string &value) { this->altText = value; }

        const std::map<std::string, Cut> &getCuts() const { return cuts; }
        std::map<std::string, Cut> &getMutableCuts() { return cuts; }
        void setCuts(const std::map<std::string, Cut> &value) {
            this->cuts = value;
        }
    };

    enum class State : int { A };

    enum class PurpleType : int { PLAYER_CARD };

    class ArakGroundhog {
      public:
        ArakGroundhog() = default;
        virtual ~ArakGroundhog() = default;

      private:
        std::string tokenGUID;
        PurpleType type;
        std::string id;
        std::string position;
        std::string name;
        std::string seoName;

      public:
        const std::string &getTokenGUID() const { return tokenGUID; }
        std::string &getMutableTokenGUID() { return tokenGUID; }
        void setTokenGUID(const std::string &value) { this->tokenGUID = value; }

        const PurpleType &getType() const { return type; }
        PurpleType &getMutableType() { return type; }
        void setType(const PurpleType &value) { this->type = value; }

        const std::string &getID() const { return id; }
        std::string &getMutableID() { return id; }
        void setID(const std::string &value) { this->id = value; }

        const std::string &getPosition() const { return position; }
        std::string &getMutablePosition() { return position; }
        void setPosition(const std::string &value) { this->position = value; }

        const std::string &getName() const { return name; }
        std::string &getMutableName() { return name; }
        void setName(const std::string &value) { this->name = value; }

        const std::string &getSEOName() const { return seoName; }
        std::string &getMutableSEOName() { return seoName; }
        void setSEOName(const std::string &value) { this->seoName = value; }
    };

    enum class DateEnum : int {
        THE_20180610_T13_05000400,
        THE_20180610_T13_07000400,
        THE_20180610_T13_10000400,
        THE_20180610_T13_35000400,
        THE_20180610_T14_10000400,
        THE_20180610_T14_20000400,
        THE_20180610_T15_05000400,
        THE_20180610_T15_10000400,
        THE_20180610_T16_05000400,
        THE_20180610_T16_10000400,
        THE_20180610_T20_05000400
    };

    class MediaUrls {
      public:
        MediaUrls() = default;
        virtual ~MediaUrls() = default;

      private:
        std::string flash450K400X224;
        std::string flash1200K640X360;
        std::string flash1800K960X540;
        std::string flash2500K1280X720;
        std::string httpCloudMobile;
        std::string httpCloudTablet;
        std::string httpCloudTablet60;
        std::string httpCloudAndroidTablet;
        std::string httpCloudWired;
        std::string httpCloudWired60;
        std::string httpCloudWiredWeb;

      public:
        const std::string &getFlash450K400X224() const {
            return flash450K400X224;
        }
        std::string &getMutableFlash450K400X224() { return flash450K400X224; }
        void setFlash450K400X224(const std::string &value) {
            this->flash450K400X224 = value;
        }

        const std::string &getFlash1200K640X360() const {
            return flash1200K640X360;
        }
        std::string &getMutableFlash1200K640X360() { return flash1200K640X360; }
        void setFlash1200K640X360(const std::string &value) {
            this->flash1200K640X360 = value;
        }

        const std::string &getFlash1800K960X540() const {
            return flash1800K960X540;
        }
        std::string &getMutableFlash1800K960X540() { return flash1800K960X540; }
        void setFlash1800K960X540(const std::string &value) {
            this->flash1800K960X540 = value;
        }

        const std::string &getFlash2500K1280X720() const {
            return flash2500K1280X720;
        }
        std::string &getMutableFlash2500K1280X720() {
            return flash2500K1280X720;
        }
        void setFlash2500K1280X720(const std::string &value) {
            this->flash2500K1280X720 = value;
        }

        const std::string &getHTTPCloudMobile() const {
            return httpCloudMobile;
        }
        std::string &getMutableHTTPCloudMobile() { return httpCloudMobile; }
        void setHTTPCloudMobile(const std::string &value) {
            this->httpCloudMobile = value;
        }

        const std::string &getHTTPCloudTablet() const {
            return httpCloudTablet;
        }
        std::string &getMutableHTTPCloudTablet() { return httpCloudTablet; }
        void setHTTPCloudTablet(const std::string &value) {
            this->httpCloudTablet = value;
        }

        const std::string &getHTTPCloudTablet60() const {
            return httpCloudTablet60;
        }
        std::string &getMutableHTTPCloudTablet60() { return httpCloudTablet60; }
        void setHTTPCloudTablet60(const std::string &value) {
            this->httpCloudTablet60 = value;
        }

        const std::string &getHTTPCloudAndroidTablet() const {
            return httpCloudAndroidTablet;
        }
        std::string &getMutableHTTPCloudAndroidTablet() {
            return httpCloudAndroidTablet;
        }
        void setHTTPCloudAndroidTablet(const std::string &value) {
            this->httpCloudAndroidTablet = value;
        }

        const std::string &getHTTPCloudWired() const { return httpCloudWired; }
        std::string &getMutableHTTPCloudWired() { return httpCloudWired; }
        void setHTTPCloudWired(const std::string &value) {
            this->httpCloudWired = value;
        }

        const std::string &getHTTPCloudWired60() const {
            return httpCloudWired60;
        }
        std::string &getMutableHTTPCloudWired60() { return httpCloudWired60; }
        void setHTTPCloudWired60(const std::string &value) {
            this->httpCloudWired60 = value;
        }

        const std::string &getHTTPCloudWiredWeb() const {
            return httpCloudWiredWeb;
        }
        std::string &getMutableHTTPCloudWiredWeb() { return httpCloudWiredWeb; }
        void setHTTPCloudWiredWeb(const std::string &value) {
            this->httpCloudWiredWeb = value;
        }
    };

    class Tag {
      public:
        Tag() = default;
        virtual ~Tag() = default;

      private:
        TypeEnum type;
        std::string value;
        std::shared_ptr<std::string> displayName;

      public:
        const TypeEnum &getType() const { return type; }
        TypeEnum &getMutableType() { return type; }
        void setType(const TypeEnum &value) { this->type = value; }

        const std::string &getValue() const { return value; }
        std::string &getMutableValue() { return value; }
        void setValue(const std::string &value) { this->value = value; }

        std::shared_ptr<std::string> getDisplayName() const {
            return displayName;
        }
        void setDisplayName(std::shared_ptr<std::string> value) {
            this->displayName = value;
        }
    };

    enum class FluffyType : int { VIDEO };

    class ChiangMaiGoose {
      public:
        ChiangMaiGoose() = default;
        virtual ~ChiangMaiGoose() = default;

      private:
        std::string tokenGUID;
        FluffyType type;
        std::string videoID;
        std::string href;
        std::vector<Tag> tags;
        DateEnum date;
        std::string headline;
        std::string duration;
        std::string blurb;
        std::shared_ptr<std::string> bigBlurb;
        std::string previewImage;
        std::string playbackURLMobile;
        std::string playbackURLTablet;
        MediaUrls mediaURLS;
        std::shared_ptr<bool> shareable;

      public:
        const std::string &getTokenGUID() const { return tokenGUID; }
        std::string &getMutableTokenGUID() { return tokenGUID; }
        void setTokenGUID(const std::string &value) { this->tokenGUID = value; }

        const FluffyType &getType() const { return type; }
        FluffyType &getMutableType() { return type; }
        void setType(const FluffyType &value) { this->type = value; }

        const std::string &getVideoID() const { return videoID; }
        std::string &getMutableVideoID() { return videoID; }
        void setVideoID(const std::string &value) { this->videoID = value; }

        const std::string &getHref() const { return href; }
        std::string &getMutableHref() { return href; }
        void setHref(const std::string &value) { this->href = value; }

        const std::vector<Tag> &getTags() const { return tags; }
        std::vector<Tag> &getMutableTags() { return tags; }
        void setTags(const std::vector<Tag> &value) { this->tags = value; }

        const DateEnum &getDate() const { return date; }
        DateEnum &getMutableDate() { return date; }
        void setDate(const DateEnum &value) { this->date = value; }

        const std::string &getHeadline() const { return headline; }
        std::string &getMutableHeadline() { return headline; }
        void setHeadline(const std::string &value) { this->headline = value; }

        const std::string &getDuration() const { return duration; }
        std::string &getMutableDuration() { return duration; }
        void setDuration(const std::string &value) { this->duration = value; }

        const std::string &getBlurb() const { return blurb; }
        std::string &getMutableBlurb() { return blurb; }
        void setBlurb(const std::string &value) { this->blurb = value; }

        std::shared_ptr<std::string> getBigBlurb() const { return bigBlurb; }
        void setBigBlurb(std::shared_ptr<std::string> value) {
            this->bigBlurb = value;
        }

        const std::string &getPreviewImage() const { return previewImage; }
        std::string &getMutablePreviewImage() { return previewImage; }
        void setPreviewImage(const std::string &value) {
            this->previewImage = value;
        }

        const std::string &getPlaybackURLMobile() const {
            return playbackURLMobile;
        }
        std::string &getMutablePlaybackURLMobile() { return playbackURLMobile; }
        void setPlaybackURLMobile(const std::string &value) {
            this->playbackURLMobile = value;
        }

        const std::string &getPlaybackURLTablet() const {
            return playbackURLTablet;
        }
        std::string &getMutablePlaybackURLTablet() { return playbackURLTablet; }
        void setPlaybackURLTablet(const std::string &value) {
            this->playbackURLTablet = value;
        }

        const MediaUrls &getMediaURLS() const { return mediaURLS; }
        MediaUrls &getMutableMediaURLS() { return mediaURLS; }
        void setMediaURLS(const MediaUrls &value) { this->mediaURLS = value; }

        std::shared_ptr<bool> getShareable() const { return shareable; }
        void setShareable(std::shared_ptr<bool> value) {
            this->shareable = value;
        }
    };

    enum class TentacledType : int { HYPER_LINK };

    class Token {
      public:
        Token() = default;
        virtual ~Token() = default;

      private:
        std::string tokenGUID;
        TentacledType type;
        std::string href;
        std::string hrefMobile;

      public:
        const std::string &getTokenGUID() const { return tokenGUID; }
        std::string &getMutableTokenGUID() { return tokenGUID; }
        void setTokenGUID(const std::string &value) { this->tokenGUID = value; }

        const TentacledType &getType() const { return type; }
        TentacledType &getMutableType() { return type; }
        void setType(const TentacledType &value) { this->type = value; }

        const std::string &getHref() const { return href; }
        std::string &getMutableHref() { return href; }
        void setHref(const std::string &value) { this->href = value; }

        const std::string &getHrefMobile() const { return hrefMobile; }
        std::string &getMutableHrefMobile() { return hrefMobile; }
        void setHrefMobile(const std::string &value) {
            this->hrefMobile = value;
        }
    };

    class Token31Dc1509Db328F11Ce0Ac {
      public:
        Token31Dc1509Db328F11Ce0Ac() = default;
        virtual ~Token31Dc1509Db328F11Ce0Ac() = default;

      private:
        std::string tokenGUID;
        std::string type;
        std::string subType;
        std::string embedID;
        std::string authorName;
        std::string authorURL;
        nlohmann::json height;
        int64_t width;
        std::string html;
        std::string href;

      public:
        const std::string &getTokenGUID() const { return tokenGUID; }
        std::string &getMutableTokenGUID() { return tokenGUID; }
        void setTokenGUID(const std::string &value) { this->tokenGUID = value; }

        const std::string &getType() const { return type; }
        std::string &getMutableType() { return type; }
        void setType(const std::string &value) { this->type = value; }

        const std::string &getSubType() const { return subType; }
        std::string &getMutableSubType() { return subType; }
        void setSubType(const std::string &value) { this->subType = value; }

        const std::string &getEmbedID() const { return embedID; }
        std::string &getMutableEmbedID() { return embedID; }
        void setEmbedID(const std::string &value) { this->embedID = value; }

        const std::string &getAuthorName() const { return authorName; }
        std::string &getMutableAuthorName() { return authorName; }
        void setAuthorName(const std::string &value) {
            this->authorName = value;
        }

        const std::string &getAuthorURL() const { return authorURL; }
        std::string &getMutableAuthorURL() { return authorURL; }
        void setAuthorURL(const std::string &value) { this->authorURL = value; }

        const nlohmann::json &getHeight() const { return height; }
        nlohmann::json &getMutableHeight() { return height; }
        void setHeight(const nlohmann::json &value) { this->height = value; }

        const int64_t &getWidth() const { return width; }
        int64_t &getMutableWidth() { return width; }
        void setWidth(const int64_t &value) { this->width = value; }

        const std::string &getHTML() const { return html; }
        std::string &getMutableHTML() { return html; }
        void setHTML(const std::string &value) { this->html = value; }

        const std::string &getHref() const { return href; }
        std::string &getMutableHref() { return href; }
        void setHref(const std::string &value) { this->href = value; }
    };

    class TokenData {
      public:
        TokenData() = default;
        virtual ~TokenData() = default;

      private:
        std::shared_ptr<Token> token23730D7C7D9AA9F7C5E85;
        std::shared_ptr<ChiangMaiGoose> tokenC91ACC313F379CD2B52B8;
        std::shared_ptr<ChiangMaiGoose> tokenE6D877BB9EC2A8D9D039C;
        std::shared_ptr<ChiangMaiGoose> token56D431904961877F1F5BE;
        std::shared_ptr<ChiangMaiGoose> token412467956BE5CDFFAF4B2;
        std::shared_ptr<ChiangMaiGoose> token5DAE442BC99D96A8B96BF;
        std::shared_ptr<ChiangMaiGoose> token9FA7F2E5B8A9875EE0B94;
        std::shared_ptr<ChiangMaiGoose> token460084A221436934CEBBE;
        std::shared_ptr<ArakGroundhog> token275E1DD943030C5B5FB9D;
        std::shared_ptr<ArakGroundhog> token212DE831C266CB42802BC;
        std::shared_ptr<ArakGroundhog> tokenE09A5C6B0D7BB2C4551B6;
        std::shared_ptr<ArakGroundhog> token3055644DABCB711618A81;
        std::shared_ptr<ArakGroundhog> token8D9DAA42490BC0B227599;
        std::shared_ptr<ArakGroundhog> token760E83788F63C48DDF7AD;
        std::shared_ptr<ArakGroundhog> tokenACEB6A8D4FD80CC07ECA7;
        std::shared_ptr<ArakGroundhog> token91AD363841ED76C7060A7;
        std::shared_ptr<ArakGroundhog> token68CA80F95ED6B4A6A77A8;
        std::shared_ptr<ArakGroundhog> token55F7368BE04958F4173A0;
        std::shared_ptr<ArakGroundhog> token64CD4F91E838690A6C98F;
        std::shared_ptr<ArakGroundhog> token5F3A93356640B35066AB0;
        std::shared_ptr<ArakGroundhog> tokenF352FC9E205DF80BBB9A1;
        std::shared_ptr<ArakGroundhog> tokenCC4A8F62FBB98029F49BA;
        std::shared_ptr<ArakGroundhog> token9C784204BF18430ED5BB4;
        std::shared_ptr<ArakGroundhog> tokenF1B435C49B4E098FEC386;
        std::shared_ptr<ArakGroundhog> token549ED10CFB146448E9CBD;
        std::shared_ptr<ArakGroundhog> tokenFC81372023C05244CC0BE;
        std::shared_ptr<ArakGroundhog> tokenA01CA209CC332D81E0489;
        std::shared_ptr<ArakGroundhog> tokenF7330F5A16C0560ED6CA4;
        std::shared_ptr<ArakGroundhog> tokenE673EA12C41DA76D45188;
        std::shared_ptr<ArakGroundhog> token2836C14E0570C3E685693;
        std::shared_ptr<ArakGroundhog> token234DA65DCF4B07EE7FAB9;
        std::shared_ptr<ArakGroundhog> token3AF0395C10670B84922A4;
        std::shared_ptr<ArakGroundhog> token1991AA23E3C62AA661FAC;
        std::shared_ptr<ChiangMaiGoose> token8E0C32852C68A118C76A7;
        std::shared_ptr<ChiangMaiGoose> tokenC23474240906E85A9AF97;
        std::shared_ptr<ChiangMaiGoose> token66285580C871C449AA2AF;
        std::shared_ptr<ChiangMaiGoose> token8584EAFA2CD964D3F359D;
        std::shared_ptr<ChiangMaiGoose> token6745E57514242D6D69782;
        std::shared_ptr<ChiangMaiGoose> token38928BB57CE50F1C31FAD;
        std::shared_ptr<ArakGroundhog> token9C0B2BEAA6DFD31524EAB;
        std::shared_ptr<ArakGroundhog> token1CD29147D64EBEEBB8F9F;
        std::shared_ptr<ArakGroundhog> tokenF4B9964747E6117A18D9E;
        std::shared_ptr<ArakGroundhog> token9537EB58E6571B5018A88;
        std::shared_ptr<ArakGroundhog> tokenE3D3B4D9DE79219AF61B5;
        std::shared_ptr<ArakGroundhog> tokenE44A9E703B514FE9DCF8F;
        std::shared_ptr<ArakGroundhog> token6A498B883DC78DF271CAB;
        std::shared_ptr<ArakGroundhog> token457F3E65BD903C1FC8AAE;
        std::shared_ptr<ArakGroundhog> tokenB952619F7911BD23953BD;
        std::shared_ptr<ArakGroundhog> token5FB0AA57C2A4D9A752093;
        std::shared_ptr<ArakGroundhog> token403A70FFCF76D500D0492;
        std::shared_ptr<ArakGroundhog> token2BF7F992E24CB42B8F497;
        std::shared_ptr<ArakGroundhog> tokenD11FB99FC582DA9D129A9;
        std::shared_ptr<ChiangMaiGoose> token37F9A03CEE7D128E78F8E;
        std::shared_ptr<ChiangMaiGoose> tokenF1AC4F490B957534BC2BA;
        std::shared_ptr<Token> tokenEE5431A399A2EA755F985;
        std::shared_ptr<Token> token7C7D7205D6AF7E6A35AB6;
        std::shared_ptr<ChiangMaiGoose> token7FEFC21E98FBD0DE662BE;
        std::shared_ptr<ChiangMaiGoose> token5F4FCB0691087ABE512A6;
        std::shared_ptr<ChiangMaiGoose> token73B814D8560F9AB7FA181;
        std::shared_ptr<ChiangMaiGoose> token1BE5802AEE0CBAB99B882;
        std::shared_ptr<ChiangMaiGoose> token9F7A70A34D6F5C0FB3E88;
        std::shared_ptr<ChiangMaiGoose> token9BBD87FF0925CB6CBA2A6;
        std::shared_ptr<ArakGroundhog> tokenE973C7D95C067E9422E89;
        std::shared_ptr<ArakGroundhog> token4A8B125DFC764AAB727A7;
        std::shared_ptr<ArakGroundhog> token05E57D99C3CD69F05C7BC;
        std::shared_ptr<ArakGroundhog> tokenF889173B1228AC1E84FA3;
        std::shared_ptr<ArakGroundhog> tokenDD46C0D463EB26DE473B5;
        std::shared_ptr<ArakGroundhog> tokenE76ABAC6694B03E9CE087;
        std::shared_ptr<ArakGroundhog> tokenD28FD03E38ACE143DF1BA;
        std::shared_ptr<ArakGroundhog> token020A9754A3089AC08B48C;
        std::shared_ptr<ArakGroundhog> token5F5D6D55FC1A1735A8C91;
        std::shared_ptr<ArakGroundhog> tokenCEA6AB430FA895B14D38C;
        std::shared_ptr<ArakGroundhog> token69F211937F19241D2719A;
        std::shared_ptr<ArakGroundhog> tokenB23C7403A039BD742F790;
        std::shared_ptr<ArakGroundhog> token7FFE1F12B5DE3C78BD5B3;
        std::shared_ptr<ArakGroundhog> tokenC2FB3EC7DD3C5A14987A4;
        std::shared_ptr<ArakGroundhog> token189330D6BFCA399608FB4;
        std::shared_ptr<ArakGroundhog> tokenAF767EF443126B3CCD8AF;
        std::shared_ptr<ArakGroundhog> token773BE241B74FA7597F780;
        std::shared_ptr<ArakGroundhog> token1BE823E3464AD53321FB1;
        std::shared_ptr<ArakGroundhog> token5F162503444CFEC22AF81;
        std::shared_ptr<ArakGroundhog> token13ACDBA5AF1CC23DF99BA;
        std::shared_ptr<ArakGroundhog> token9FDF39287E87C1B324894;
        std::shared_ptr<ArakGroundhog> tokenA32E4613028FD614C2992;
        std::shared_ptr<ArakGroundhog> tokenA433BA409058D6BE952A5;
        std::shared_ptr<ArakGroundhog> token7CF34D79E5F77AD7595B5;
        std::shared_ptr<ArakGroundhog> token92B8DA5E1E3E67C80D793;
        std::shared_ptr<ArakGroundhog> token75BD980A2FAC6679C9CA9;
        std::shared_ptr<ArakGroundhog> token804528C0EDB6908B0B899;
        std::shared_ptr<ArakGroundhog> tokenCBA976567E4283E3E9E9B;
        std::shared_ptr<ArakGroundhog> token99C6A24D2A561187A77BA;
        std::shared_ptr<ArakGroundhog> token25B4946A8DC84F7E5F0AA;
        std::shared_ptr<ArakGroundhog> tokenC75FA378013EC28E08CA9;
        std::shared_ptr<ArakGroundhog> token4B8879991B0C58A8DE786;
        std::shared_ptr<Token> token5DC7CA1D490AB35523D9E;
        std::shared_ptr<ChiangMaiGoose> token7D071A1FBCAE3D2EC0C90;
        std::shared_ptr<ChiangMaiGoose> tokenD9214DB82A79855D1859D;
        std::shared_ptr<ChiangMaiGoose> token410A7675F420C35808D87;
        std::shared_ptr<ChiangMaiGoose> tokenA9E0E34E0D049ABBC058C;
        std::shared_ptr<ChiangMaiGoose> token6606AC90A18517646E98C;
        std::shared_ptr<Token31Dc1509Db328F11Ce0Ac> token31DC1509DB328F11CE0AC;
        std::shared_ptr<ArakGroundhog> token2257B2C2C7580FB792CA6;
        std::shared_ptr<ArakGroundhog> token9DF69821A140BE2EE72A7;
        std::shared_ptr<ChiangMaiGoose> token73FE56D22D475C7AEDDBC;
        std::shared_ptr<ChiangMaiGoose> tokenC5CF6A9EB1465D3AA6FB2;
        std::shared_ptr<ChiangMaiGoose> token52486AA7D796B2255BFAC;
        std::shared_ptr<ChiangMaiGoose> tokenB5C1EE76A29C4B9565FA4;
        std::shared_ptr<ChiangMaiGoose> token484BB1EF60EDADE1B5F87;
        std::shared_ptr<ChiangMaiGoose> tokenCC0C3139115704DDCD9B5;
        std::shared_ptr<ChiangMaiGoose> tokenF982C7EC74EC42B045292;
        std::shared_ptr<ArakGroundhog> tokenE21184507C5F3D50DB6B7;
        std::shared_ptr<ArakGroundhog> tokenD45E9BEA4A13EF51DEBAA;
        std::shared_ptr<ArakGroundhog> tokenB6862EBB8098F3A7844B2;
        std::shared_ptr<ArakGroundhog> tokenE4172A6C64523DEA10F86;
        std::shared_ptr<ArakGroundhog> tokenA95061722FE9A77D1DFBF;
        std::shared_ptr<ArakGroundhog> token5B69AE3AA1EF011AAD4B3;
        std::shared_ptr<ArakGroundhog> token66A3AAAD4DD83FCA1879F;
        std::shared_ptr<ArakGroundhog> tokenF8E4C5685995705F88B92;
        std::shared_ptr<ArakGroundhog> tokenC00E691B0A55A2DD43EB8;
        std::shared_ptr<ArakGroundhog> token9F9B02979A0DF3CC4778D;
        std::shared_ptr<ArakGroundhog> tokenDC19D53DD6052509AD1A3;
        std::shared_ptr<ArakGroundhog> token4AA54B21F152FC8DF76AF;
        std::shared_ptr<ArakGroundhog> token0A1129926CF5AB0429CBF;
        std::shared_ptr<ArakGroundhog> tokenDD5788037C4E041210AA5;
        std::shared_ptr<ArakGroundhog> tokenAD10645A4F87DE5EB0BAE;
        std::shared_ptr<Token> tokenEB8B0C94A2755E7867D88;
        std::shared_ptr<Token> token070C5B4CF3C6A0525EF8A;
        std::shared_ptr<ChiangMaiGoose> token2005A2B8966B82D1465B0;
        std::shared_ptr<ChiangMaiGoose> tokenEEC2396B3AA201D183BB2;
        std::shared_ptr<ChiangMaiGoose> token6F19EA16BAF005F8A9890;
        std::shared_ptr<ChiangMaiGoose> token6D2EAF6B75B43DAFAE6B5;
        std::shared_ptr<ChiangMaiGoose> token22D7AA24310E5C01DD7A6;
        std::shared_ptr<ChiangMaiGoose> tokenB073BFD6F6F1A54561AAA;
        std::shared_ptr<ChiangMaiGoose> tokenDC4D65D0323293BD9FFBE;
        std::shared_ptr<ChiangMaiGoose> token864AD60BCF6F538F88098;
        std::shared_ptr<ChiangMaiGoose> token0A5BB893872F8C8C67DB9;
        std::shared_ptr<ChiangMaiGoose> tokenBE0C2097C4F2C19F66CA2;
        std::shared_ptr<ArakGroundhog> token4BFDDDF8D2722BCE14B9E;
        std::shared_ptr<ArakGroundhog> tokenD54C011E1AB9599CC109C;
        std::shared_ptr<ArakGroundhog> tokenD98EE3E8307B8F045AFB2;
        std::shared_ptr<ArakGroundhog> tokenF09F92BD69607DA9FA58A;
        std::shared_ptr<ArakGroundhog> token8895755EBF6C843217193;
        std::shared_ptr<ArakGroundhog> token4DAA1881652DB60C7A69D;
        std::shared_ptr<ArakGroundhog> token5CE56514A2C581E3548BB;
        std::shared_ptr<ArakGroundhog> token5286121206A18BC880CA1;
        std::shared_ptr<ArakGroundhog> token0BC3D6C3440A378947E9E;
        std::shared_ptr<ArakGroundhog> token1017E26B4547892961C93;
        std::shared_ptr<ArakGroundhog> tokenF97DBB4ABBD980541AC92;
        std::shared_ptr<ArakGroundhog> token14FD201B1642E4F7C22AE;
        std::shared_ptr<ArakGroundhog> token284542EA81AA0A8F9F3BA;
        std::shared_ptr<ArakGroundhog> tokenDD6AB438DB39A46267791;
        std::shared_ptr<ArakGroundhog> token914A425A0D1A67AE16FB4;
        std::shared_ptr<ArakGroundhog> token2713B53B467F1FC0859A4;
        std::shared_ptr<ArakGroundhog> token6AA83D1F06D61FA4B04A0;
        std::shared_ptr<ChiangMaiGoose> tokenEB80AFBF5ECC14E2B7A97;
        std::shared_ptr<ChiangMaiGoose> tokenBC7FA51814A6539D0E198;
        std::shared_ptr<ChiangMaiGoose> tokenF29ABE717AA237771A58D;
        std::shared_ptr<ChiangMaiGoose> tokenABC0CCBD80F4B6A73E183;
        std::shared_ptr<ArakGroundhog> token91A96AB72040DB15F0889;
        std::shared_ptr<ArakGroundhog> token02AE741A1216657EB1EA3;
        std::shared_ptr<ArakGroundhog> token525BAB7BA21A8C4171196;
        std::shared_ptr<ArakGroundhog> tokenC3E6904C99D6546B4D1A6;
        std::shared_ptr<ArakGroundhog> token3B4A3A61505C0DAB9B296;
        std::shared_ptr<ArakGroundhog> token131E682AB43965E3CD08D;
        std::shared_ptr<ArakGroundhog> tokenCD041A7D69BDD9C7BE3BB;
        std::shared_ptr<ArakGroundhog> token05947572D06DE1DB8A298;
        std::shared_ptr<ArakGroundhog> token40A59E33FB628C84D12A6;
        std::shared_ptr<ArakGroundhog> token81D360AE1966FE4A13498;
        std::shared_ptr<ArakGroundhog> token7F4D4B46F0D3F3E6B948B;
        std::shared_ptr<ArakGroundhog> tokenCD527524FFFCC134E68AD;
        std::shared_ptr<ArakGroundhog> token09331C5A2FC68D6A37C8C;
        std::shared_ptr<ArakGroundhog> token5E8B97B8BC1CCFE672D84;
        std::shared_ptr<ArakGroundhog> token1919A40BACD45BF456583;
        std::shared_ptr<ArakGroundhog> tokenCF7DBB43C1BEC8B7E0583;
        std::shared_ptr<ArakGroundhog> tokenF9E4FCCF2958D99771DB5;
        std::shared_ptr<ArakGroundhog> token6EA6D99DA254E66ECA4BF;
        std::shared_ptr<ArakGroundhog> token325C6E6F0D4C917F612AC;
        std::shared_ptr<Token> tokenC95E7E943D1FADFDB65A2;
        std::shared_ptr<ArakGroundhog> tokenA930040748B7AD6919CB7;
        std::shared_ptr<ChiangMaiGoose> token8BC82DBF7A9FF9D0E9795;
        std::shared_ptr<ChiangMaiGoose> token2D1004923EAF1526F8C81;
        std::shared_ptr<ChiangMaiGoose> token0C2DC1EE6F9A4340DFCA2;
        std::shared_ptr<ChiangMaiGoose> tokenDA8C7775F48B125F296AA;
        std::shared_ptr<ChiangMaiGoose> tokenC079D392173F6252A9B96;
        std::shared_ptr<ChiangMaiGoose> token30AAEC5419E5CFBE0619B;
        std::shared_ptr<ChiangMaiGoose> token51C9117EDCCFBD4113183;
        std::shared_ptr<ChiangMaiGoose> token1A23A0729B946F42B568D;
        std::shared_ptr<ArakGroundhog> token8D1C936FAD8E7FB2960A3;
        std::shared_ptr<ArakGroundhog> tokenAE13DCA77AB5E5C238D96;
        std::shared_ptr<ArakGroundhog> token965804858147E711BBDA7;
        std::shared_ptr<ArakGroundhog> tokenCED72F9484959B5E5E8A3;
        std::shared_ptr<ArakGroundhog> token748E8715DE7C703B363BD;
        std::shared_ptr<ArakGroundhog> tokenC1AA59A330DD13689138B;
        std::shared_ptr<ArakGroundhog> tokenDA38780E0D36911690096;
        std::shared_ptr<ArakGroundhog> tokenE9BAFFD7C98371BA1389D;
        std::shared_ptr<ArakGroundhog> token4916780C4CF9BD3B22099;
        std::shared_ptr<ArakGroundhog> token710FCFBA6F2FE3A761E99;
        std::shared_ptr<ArakGroundhog> tokenA8B1CBDAB3AEBB9A166A2;
        std::shared_ptr<ArakGroundhog> token71491BF388DB005F10385;
        std::shared_ptr<ArakGroundhog> token5D62DC906634BE78EFCB4;
        std::shared_ptr<ArakGroundhog> tokenAA104BAE32C34D8AFA1A2;
        std::shared_ptr<ArakGroundhog> token6702818DD29E09D9A22A7;
        std::shared_ptr<ArakGroundhog> token99BC3D2DE1717F82E2999;
        std::shared_ptr<ArakGroundhog> tokenB3E5E87E867AE2D9B27AC;
        std::shared_ptr<ArakGroundhog> token252B7A2AD40FEA145BD85;
        std::shared_ptr<ArakGroundhog> tokenE8FDD64E18F3710D7EE89;
        std::shared_ptr<ArakGroundhog> tokenDC53EE2DE0CA847341D8B;
        std::shared_ptr<ArakGroundhog> token1A7FC9AA0C41A32752294;
        std::shared_ptr<ArakGroundhog> token5E258FBC355B5959040BC;
        std::shared_ptr<ChiangMaiGoose> token0676E8BC26CADB6BAD3AA;
        std::shared_ptr<ChiangMaiGoose> token43A0D255D3D202BDEFCB3;
        std::shared_ptr<ChiangMaiGoose> token2753FA17589D44632BB9F;
        std::shared_ptr<ChiangMaiGoose> token72D8015C5A42F10EC718C;
        std::shared_ptr<ChiangMaiGoose> token537662B35E180A527F7A0;
        std::shared_ptr<ChiangMaiGoose> tokenE0E410C8AC996EB11CB85;
        std::shared_ptr<ArakGroundhog> token9B1067E1332C4D152B1AD;
        std::shared_ptr<ArakGroundhog> token1763F37EE500EF4E84E83;
        std::shared_ptr<ArakGroundhog> tokenCD4BEFC7BB8BD00D5A5A9;
        std::shared_ptr<ArakGroundhog> token7A458795BD4B0D95651B7;
        std::shared_ptr<ArakGroundhog> token59C91F284D3472DE5B08D;
        std::shared_ptr<ArakGroundhog> token2F1CE8C3537D39C3B42A3;
        std::shared_ptr<ArakGroundhog> token0055D3A7A18B4580C8F8C;
        std::shared_ptr<ArakGroundhog> tokenE34215A0C5DCD9035DC83;
        std::shared_ptr<ArakGroundhog> token10D15272527BD16B97E84;
        std::shared_ptr<ArakGroundhog> token0DE01F3020C5A5A702F9A;
        std::shared_ptr<ArakGroundhog> token9A446B4684FA2B2656ABE;
        std::shared_ptr<ArakGroundhog> tokenCD7E5318FC7C9816CD7B0;
        std::shared_ptr<ArakGroundhog> token013C382D3D890D3B1FEA7;
        std::shared_ptr<ArakGroundhog> token845B0B9C1B8874A7C2CB6;
        std::shared_ptr<ArakGroundhog> tokenB5E715791898691F8D780;
        std::shared_ptr<ArakGroundhog> tokenC159A044375814C6307A2;
        std::shared_ptr<Token> token06D8C451D01C967B2A889;
        std::shared_ptr<ChiangMaiGoose> token4947D300F5746CB9327A9;
        std::shared_ptr<ChiangMaiGoose> tokenDBC3DD3DD9962086D98B8;
        std::shared_ptr<ChiangMaiGoose> token90B46B4771085F9F64087;
        std::shared_ptr<ChiangMaiGoose> tokenDA864C7498ED439B5D095;
        std::shared_ptr<ChiangMaiGoose> token8EDE4E47E55E8945128AC;
        std::shared_ptr<Token> token4F9CEBFCB2BCB7C1F93AE;
        std::shared_ptr<ArakGroundhog> tokenC0E5BD48806EA05D8E1B3;
        std::shared_ptr<ArakGroundhog> tokenA713AE88B171CF6DE2584;
        std::shared_ptr<ArakGroundhog> token71FE836A3546F7800028F;
        std::shared_ptr<ArakGroundhog> tokenBF85C9CB2643D2241AFBE;
        std::shared_ptr<ArakGroundhog> tokenED59CC7C7EBD1C981D9AD;
        std::shared_ptr<ArakGroundhog> tokenCCF87B3D65FD49EECC6A4;
        std::shared_ptr<ArakGroundhog> token238BE16B560DAFB40A8B3;
        std::shared_ptr<ArakGroundhog> token88767604C712FA84DE2B4;
        std::shared_ptr<ArakGroundhog> token896C4E49DF74696BBBB8E;
        std::shared_ptr<ChiangMaiGoose> token2884443F1CDB74F7E97A7;
        std::shared_ptr<ChiangMaiGoose> tokenCD0D1A32B252CB1328B9A;
        std::shared_ptr<ChiangMaiGoose> token213D74984AAA195477685;
        std::shared_ptr<ChiangMaiGoose> token594687C9B2CA65E5CB496;
        std::shared_ptr<Token> tokenEC6AA0C48EEA99823E1A2;
        std::shared_ptr<ArakGroundhog> token896463C5DE287BB120E80;
        std::shared_ptr<ArakGroundhog> tokenB7B473A156B5AFEF56FA3;
        std::shared_ptr<ArakGroundhog> tokenBA252399CE2C5F9194790;
        std::shared_ptr<ArakGroundhog> tokenD65725A7C3014B742D999;
        std::shared_ptr<ArakGroundhog> token88AB56442BF560EA449A1;
        std::shared_ptr<ArakGroundhog> token9E6C96FBA7639E73BCE9D;
        std::shared_ptr<ArakGroundhog> token4201CDF79A2F9160671B3;
        std::shared_ptr<ArakGroundhog> token868303FF0484A110D1293;
        std::shared_ptr<ArakGroundhog> token85AD0DE8698EA728E5D9C;
        std::shared_ptr<ArakGroundhog> tokenFCF78BB01006B90686088;
        std::shared_ptr<ArakGroundhog> tokenA2BD2B5293660FB1173A6;
        std::shared_ptr<ArakGroundhog> token01D8ECCF9F69D3E9FC7B1;
        std::shared_ptr<ArakGroundhog> token7976D7BDB91692136A1AB;
        std::shared_ptr<ArakGroundhog> tokenA86DB4585C3D45CB353AD;
        std::shared_ptr<ArakGroundhog> token71EB4680E8A3A35BA0FB0;
        std::shared_ptr<ArakGroundhog> tokenEEAF0DEE6AD40E74DA5BC;
        std::shared_ptr<ArakGroundhog> tokenEA6E3BE35693BB6FB8BB7;
        std::shared_ptr<ArakGroundhog> tokenCEA2074211CEEBD9B5DB3;
        std::shared_ptr<ArakGroundhog> token1C733F07F13173D19B29F;
        std::shared_ptr<ArakGroundhog> token20C940B34447AB12CCEA8;
        std::shared_ptr<ArakGroundhog> token44ABE8B7288C4D59102B5;
        std::shared_ptr<ArakGroundhog> tokenEEC6944070EA265B950B0;
        std::shared_ptr<ArakGroundhog> token4AFD25AD6666299F2A88B;
        std::shared_ptr<ArakGroundhog> token6669C3AABD6369A1AED82;
        std::shared_ptr<Token> token5B280CB8A69F3D0902EA4;
        std::shared_ptr<ChiangMaiGoose> tokenCDFF7828935B02B2CDF86;
        std::shared_ptr<ChiangMaiGoose> tokenAF8113E8B8049BAEB73B1;
        std::shared_ptr<ChiangMaiGoose> token696B050B75268E575EE84;
        std::shared_ptr<ChiangMaiGoose> token892A51A637EF5A550FDBA;
        std::shared_ptr<ChiangMaiGoose> token0DE090A2C87A61162BBA4;
        std::shared_ptr<ChiangMaiGoose> token63CC3A387F5BAEF69D4A7;
        std::shared_ptr<ChiangMaiGoose> token0B1C3C68043A4F4B61F9F;
        std::shared_ptr<ChiangMaiGoose> token0A4486D1E21D43E961BA6;
        std::shared_ptr<ChiangMaiGoose> token5282457FF22ABFDE400B4;
        std::shared_ptr<ChiangMaiGoose> tokenD8774B9492D7CBFC37CB8;
        std::shared_ptr<ArakGroundhog> token4B5D845A389A0EE19AABF;
        std::shared_ptr<ArakGroundhog> tokenE6D5489CE13AD84D8E7B7;
        std::shared_ptr<ArakGroundhog> token9FF026A883F738C0B0CB9;
        std::shared_ptr<ArakGroundhog> tokenCA96E1DBD4F7E72EED48D;
        std::shared_ptr<ArakGroundhog> token0D2CB48596748A6B4BFBA;
        std::shared_ptr<ArakGroundhog> token434F3160A979CA1009882;
        std::shared_ptr<ArakGroundhog> token9220F57D2902D463A1A8D;
        std::shared_ptr<ArakGroundhog> token096809C9884ED117FB9B6;
        std::shared_ptr<ArakGroundhog> token0189CF14C1ABB9E38D288;
        std::shared_ptr<ArakGroundhog> tokenB044BAAF3986B432AE7BF;
        std::shared_ptr<ArakGroundhog> tokenB7FA499A68198D093D8A2;
        std::shared_ptr<ArakGroundhog> token438FF67AE1F17D825FAB5;
        std::shared_ptr<ArakGroundhog> token352D769B1B3BB61DBAFBB;
        std::shared_ptr<ArakGroundhog> tokenB0F4CB473A8FDBB9CE692;
        std::shared_ptr<ArakGroundhog> tokenCF772D023E3AFAE164899;
        std::shared_ptr<Token> tokenEC7A4FC879CE357C2DF84;
        std::shared_ptr<ArakGroundhog> token089FB68037C80FE98FCAA;
        std::shared_ptr<ArakGroundhog> token346CF28DB5A65D132898E;
        std::shared_ptr<ArakGroundhog> tokenDA48586079FD76F4A9FAD;
        std::shared_ptr<ArakGroundhog> token947AF2755679C774793BA;
        std::shared_ptr<ArakGroundhog> tokenF07D4E665D02F4187439E;
        std::shared_ptr<ArakGroundhog> token9E429B12B9261F6A8A489;
        std::shared_ptr<ArakGroundhog> tokenE87D96060B9E2D539DC9B;
        std::shared_ptr<ArakGroundhog> token0FA39B41B19A62959098F;
        std::shared_ptr<ArakGroundhog> token1803E0AC70A0D57BBA981;
        std::shared_ptr<ArakGroundhog> token48A9BB431CC7D43FD5BA8;
        std::shared_ptr<ArakGroundhog> tokenD8AC4F4104AD455C85A84;
        std::shared_ptr<ArakGroundhog> tokenBF1DEF94AAFC697A6F9BA;
        std::shared_ptr<ArakGroundhog> token7D08480AD0B453BE029A8;
        std::shared_ptr<ArakGroundhog> token4473A490C2ECEA90DAAB2;
        std::shared_ptr<ArakGroundhog> tokenB17711FF64A6F6F06299D;
        std::shared_ptr<ChiangMaiGoose> token844BFDA4BE916BD54A3AA;
        std::shared_ptr<ChiangMaiGoose> token23229682C74347EEB8886;
        std::shared_ptr<ChiangMaiGoose> token60E6C57473CB0C88A3E86;
        std::shared_ptr<ChiangMaiGoose> token8C31165AE39E790CCD7B8;
        std::shared_ptr<ChiangMaiGoose> tokenFE355BF81FC13A6A0DDAE;
        std::shared_ptr<Token> tokenCF3855D906085F5BBFB8B;
        std::shared_ptr<ChiangMaiGoose> token9F00C7C0F02FB6B6BDB80;
        std::shared_ptr<ChiangMaiGoose> token672CC221DCD193EEA0093;
        std::shared_ptr<ChiangMaiGoose> token682906AC7B7E242CFC883;
        std::shared_ptr<ChiangMaiGoose> token3D725B01FB7B9FA90E387;
        std::shared_ptr<Token> token6A8D9E562B7D9BCC22487;
        std::shared_ptr<ChiangMaiGoose> tokenFCFD60AF5972635E239A1;
        std::shared_ptr<ChiangMaiGoose> token44257D2BB1EB83445748B;
        std::shared_ptr<ChiangMaiGoose> tokenC081C1B31AD23306729BC;
        std::shared_ptr<ArakGroundhog> token91EE07D52D132C0291AA9;
        std::shared_ptr<ArakGroundhog> token463C9F3509B4B3CE21890;
        std::shared_ptr<ArakGroundhog> tokenA8AE1C4637E3977ED139C;
        std::shared_ptr<ArakGroundhog> token072340E8F68E6230FB595;
        std::shared_ptr<ArakGroundhog> tokenAFEABC74E014E1FDCA189;
        std::shared_ptr<ArakGroundhog> token8C03099B0BF7559E4CC8B;
        std::shared_ptr<ArakGroundhog> tokenCAD830A007BF99AE22588;
        std::shared_ptr<ArakGroundhog> token803EDA85AD6E2152498B9;
        std::shared_ptr<ArakGroundhog> token261F79B544B15F18D90BC;
        std::shared_ptr<ArakGroundhog> token57FF4186B72441359A28C;
        std::shared_ptr<ArakGroundhog> token9636866E27CE8589EBCAF;
        std::shared_ptr<ArakGroundhog> token0651D7AAA332194B08DBE;
        std::shared_ptr<ArakGroundhog> tokenA158381332191727F40AB;
        std::shared_ptr<ArakGroundhog> token7D115BFFC746C4DE901B1;
        std::shared_ptr<ArakGroundhog> tokenDCEC566E79614AE22F599;
        std::shared_ptr<ArakGroundhog> tokenD7ECF91124B8871B9D484;
        std::shared_ptr<ArakGroundhog> token97EFEDD8F2A074CEAAE88;
        std::shared_ptr<ArakGroundhog> token3E9C3D0C2A9A1151B7B88;
        std::shared_ptr<ArakGroundhog> token39AC0A81B17950CF2D2B5;
        std::shared_ptr<ArakGroundhog> tokenAEC432518E3CF5FDE4FB5;
        std::shared_ptr<ArakGroundhog> token5A9C312E1F012AE978784;
        std::shared_ptr<Token> tokenFBD4128927E1E68A54A81;
        std::shared_ptr<ArakGroundhog> token910E582093166C1D0DF80;

      public:
        std::shared_ptr<Token> getToken23730D7C7D9AA9F7C5E85() const {
            return token23730D7C7D9AA9F7C5E85;
        }
        void setToken23730D7C7D9AA9F7C5E85(std::shared_ptr<Token> value) {
            this->token23730D7C7D9AA9F7C5E85 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenC91ACC313F379CD2B52B8() const {
            return tokenC91ACC313F379CD2B52B8;
        }
        void
        setTokenC91ACC313F379CD2B52B8(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenC91ACC313F379CD2B52B8 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenE6D877BB9EC2A8D9D039C() const {
            return tokenE6D877BB9EC2A8D9D039C;
        }
        void
        setTokenE6D877BB9EC2A8D9D039C(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenE6D877BB9EC2A8D9D039C = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken56D431904961877F1F5BE() const {
            return token56D431904961877F1F5BE;
        }
        void
        setToken56D431904961877F1F5BE(std::shared_ptr<ChiangMaiGoose> value) {
            this->token56D431904961877F1F5BE = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken412467956BE5CDFFAF4B2() const {
            return token412467956BE5CDFFAF4B2;
        }
        void
        setToken412467956BE5CDFFAF4B2(std::shared_ptr<ChiangMaiGoose> value) {
            this->token412467956BE5CDFFAF4B2 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken5DAE442BC99D96A8B96BF() const {
            return token5DAE442BC99D96A8B96BF;
        }
        void
        setToken5DAE442BC99D96A8B96BF(std::shared_ptr<ChiangMaiGoose> value) {
            this->token5DAE442BC99D96A8B96BF = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken9FA7F2E5B8A9875EE0B94() const {
            return token9FA7F2E5B8A9875EE0B94;
        }
        void
        setToken9FA7F2E5B8A9875EE0B94(std::shared_ptr<ChiangMaiGoose> value) {
            this->token9FA7F2E5B8A9875EE0B94 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken460084A221436934CEBBE() const {
            return token460084A221436934CEBBE;
        }
        void
        setToken460084A221436934CEBBE(std::shared_ptr<ChiangMaiGoose> value) {
            this->token460084A221436934CEBBE = value;
        }

        std::shared_ptr<ArakGroundhog> getToken275E1DD943030C5B5FB9D() const {
            return token275E1DD943030C5B5FB9D;
        }
        void
        setToken275E1DD943030C5B5FB9D(std::shared_ptr<ArakGroundhog> value) {
            this->token275E1DD943030C5B5FB9D = value;
        }

        std::shared_ptr<ArakGroundhog> getToken212DE831C266CB42802BC() const {
            return token212DE831C266CB42802BC;
        }
        void
        setToken212DE831C266CB42802BC(std::shared_ptr<ArakGroundhog> value) {
            this->token212DE831C266CB42802BC = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE09A5C6B0D7BB2C4551B6() const {
            return tokenE09A5C6B0D7BB2C4551B6;
        }
        void
        setTokenE09A5C6B0D7BB2C4551B6(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE09A5C6B0D7BB2C4551B6 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken3055644DABCB711618A81() const {
            return token3055644DABCB711618A81;
        }
        void
        setToken3055644DABCB711618A81(std::shared_ptr<ArakGroundhog> value) {
            this->token3055644DABCB711618A81 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken8D9DAA42490BC0B227599() const {
            return token8D9DAA42490BC0B227599;
        }
        void
        setToken8D9DAA42490BC0B227599(std::shared_ptr<ArakGroundhog> value) {
            this->token8D9DAA42490BC0B227599 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken760E83788F63C48DDF7AD() const {
            return token760E83788F63C48DDF7AD;
        }
        void
        setToken760E83788F63C48DDF7AD(std::shared_ptr<ArakGroundhog> value) {
            this->token760E83788F63C48DDF7AD = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenACEB6A8D4FD80CC07ECA7() const {
            return tokenACEB6A8D4FD80CC07ECA7;
        }
        void
        setTokenACEB6A8D4FD80CC07ECA7(std::shared_ptr<ArakGroundhog> value) {
            this->tokenACEB6A8D4FD80CC07ECA7 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken91AD363841ED76C7060A7() const {
            return token91AD363841ED76C7060A7;
        }
        void
        setToken91AD363841ED76C7060A7(std::shared_ptr<ArakGroundhog> value) {
            this->token91AD363841ED76C7060A7 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken68CA80F95ED6B4A6A77A8() const {
            return token68CA80F95ED6B4A6A77A8;
        }
        void
        setToken68CA80F95ED6B4A6A77A8(std::shared_ptr<ArakGroundhog> value) {
            this->token68CA80F95ED6B4A6A77A8 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken55F7368BE04958F4173A0() const {
            return token55F7368BE04958F4173A0;
        }
        void
        setToken55F7368BE04958F4173A0(std::shared_ptr<ArakGroundhog> value) {
            this->token55F7368BE04958F4173A0 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken64CD4F91E838690A6C98F() const {
            return token64CD4F91E838690A6C98F;
        }
        void
        setToken64CD4F91E838690A6C98F(std::shared_ptr<ArakGroundhog> value) {
            this->token64CD4F91E838690A6C98F = value;
        }

        std::shared_ptr<ArakGroundhog> getToken5F3A93356640B35066AB0() const {
            return token5F3A93356640B35066AB0;
        }
        void
        setToken5F3A93356640B35066AB0(std::shared_ptr<ArakGroundhog> value) {
            this->token5F3A93356640B35066AB0 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenF352FC9E205DF80BBB9A1() const {
            return tokenF352FC9E205DF80BBB9A1;
        }
        void
        setTokenF352FC9E205DF80BBB9A1(std::shared_ptr<ArakGroundhog> value) {
            this->tokenF352FC9E205DF80BBB9A1 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCC4A8F62FBB98029F49BA() const {
            return tokenCC4A8F62FBB98029F49BA;
        }
        void
        setTokenCC4A8F62FBB98029F49BA(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCC4A8F62FBB98029F49BA = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9C784204BF18430ED5BB4() const {
            return token9C784204BF18430ED5BB4;
        }
        void
        setToken9C784204BF18430ED5BB4(std::shared_ptr<ArakGroundhog> value) {
            this->token9C784204BF18430ED5BB4 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenF1B435C49B4E098FEC386() const {
            return tokenF1B435C49B4E098FEC386;
        }
        void
        setTokenF1B435C49B4E098FEC386(std::shared_ptr<ArakGroundhog> value) {
            this->tokenF1B435C49B4E098FEC386 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken549ED10CFB146448E9CBD() const {
            return token549ED10CFB146448E9CBD;
        }
        void
        setToken549ED10CFB146448E9CBD(std::shared_ptr<ArakGroundhog> value) {
            this->token549ED10CFB146448E9CBD = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenFC81372023C05244CC0BE() const {
            return tokenFC81372023C05244CC0BE;
        }
        void
        setTokenFC81372023C05244CC0BE(std::shared_ptr<ArakGroundhog> value) {
            this->tokenFC81372023C05244CC0BE = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenA01CA209CC332D81E0489() const {
            return tokenA01CA209CC332D81E0489;
        }
        void
        setTokenA01CA209CC332D81E0489(std::shared_ptr<ArakGroundhog> value) {
            this->tokenA01CA209CC332D81E0489 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenF7330F5A16C0560ED6CA4() const {
            return tokenF7330F5A16C0560ED6CA4;
        }
        void
        setTokenF7330F5A16C0560ED6CA4(std::shared_ptr<ArakGroundhog> value) {
            this->tokenF7330F5A16C0560ED6CA4 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE673EA12C41DA76D45188() const {
            return tokenE673EA12C41DA76D45188;
        }
        void
        setTokenE673EA12C41DA76D45188(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE673EA12C41DA76D45188 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken2836C14E0570C3E685693() const {
            return token2836C14E0570C3E685693;
        }
        void
        setToken2836C14E0570C3E685693(std::shared_ptr<ArakGroundhog> value) {
            this->token2836C14E0570C3E685693 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken234DA65DCF4B07EE7FAB9() const {
            return token234DA65DCF4B07EE7FAB9;
        }
        void
        setToken234DA65DCF4B07EE7FAB9(std::shared_ptr<ArakGroundhog> value) {
            this->token234DA65DCF4B07EE7FAB9 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken3AF0395C10670B84922A4() const {
            return token3AF0395C10670B84922A4;
        }
        void
        setToken3AF0395C10670B84922A4(std::shared_ptr<ArakGroundhog> value) {
            this->token3AF0395C10670B84922A4 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken1991AA23E3C62AA661FAC() const {
            return token1991AA23E3C62AA661FAC;
        }
        void
        setToken1991AA23E3C62AA661FAC(std::shared_ptr<ArakGroundhog> value) {
            this->token1991AA23E3C62AA661FAC = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken8E0C32852C68A118C76A7() const {
            return token8E0C32852C68A118C76A7;
        }
        void
        setToken8E0C32852C68A118C76A7(std::shared_ptr<ChiangMaiGoose> value) {
            this->token8E0C32852C68A118C76A7 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenC23474240906E85A9AF97() const {
            return tokenC23474240906E85A9AF97;
        }
        void
        setTokenC23474240906E85A9AF97(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenC23474240906E85A9AF97 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken66285580C871C449AA2AF() const {
            return token66285580C871C449AA2AF;
        }
        void
        setToken66285580C871C449AA2AF(std::shared_ptr<ChiangMaiGoose> value) {
            this->token66285580C871C449AA2AF = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken8584EAFA2CD964D3F359D() const {
            return token8584EAFA2CD964D3F359D;
        }
        void
        setToken8584EAFA2CD964D3F359D(std::shared_ptr<ChiangMaiGoose> value) {
            this->token8584EAFA2CD964D3F359D = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken6745E57514242D6D69782() const {
            return token6745E57514242D6D69782;
        }
        void
        setToken6745E57514242D6D69782(std::shared_ptr<ChiangMaiGoose> value) {
            this->token6745E57514242D6D69782 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken38928BB57CE50F1C31FAD() const {
            return token38928BB57CE50F1C31FAD;
        }
        void
        setToken38928BB57CE50F1C31FAD(std::shared_ptr<ChiangMaiGoose> value) {
            this->token38928BB57CE50F1C31FAD = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9C0B2BEAA6DFD31524EAB() const {
            return token9C0B2BEAA6DFD31524EAB;
        }
        void
        setToken9C0B2BEAA6DFD31524EAB(std::shared_ptr<ArakGroundhog> value) {
            this->token9C0B2BEAA6DFD31524EAB = value;
        }

        std::shared_ptr<ArakGroundhog> getToken1CD29147D64EBEEBB8F9F() const {
            return token1CD29147D64EBEEBB8F9F;
        }
        void
        setToken1CD29147D64EBEEBB8F9F(std::shared_ptr<ArakGroundhog> value) {
            this->token1CD29147D64EBEEBB8F9F = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenF4B9964747E6117A18D9E() const {
            return tokenF4B9964747E6117A18D9E;
        }
        void
        setTokenF4B9964747E6117A18D9E(std::shared_ptr<ArakGroundhog> value) {
            this->tokenF4B9964747E6117A18D9E = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9537EB58E6571B5018A88() const {
            return token9537EB58E6571B5018A88;
        }
        void
        setToken9537EB58E6571B5018A88(std::shared_ptr<ArakGroundhog> value) {
            this->token9537EB58E6571B5018A88 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE3D3B4D9DE79219AF61B5() const {
            return tokenE3D3B4D9DE79219AF61B5;
        }
        void
        setTokenE3D3B4D9DE79219AF61B5(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE3D3B4D9DE79219AF61B5 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE44A9E703B514FE9DCF8F() const {
            return tokenE44A9E703B514FE9DCF8F;
        }
        void
        setTokenE44A9E703B514FE9DCF8F(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE44A9E703B514FE9DCF8F = value;
        }

        std::shared_ptr<ArakGroundhog> getToken6A498B883DC78DF271CAB() const {
            return token6A498B883DC78DF271CAB;
        }
        void
        setToken6A498B883DC78DF271CAB(std::shared_ptr<ArakGroundhog> value) {
            this->token6A498B883DC78DF271CAB = value;
        }

        std::shared_ptr<ArakGroundhog> getToken457F3E65BD903C1FC8AAE() const {
            return token457F3E65BD903C1FC8AAE;
        }
        void
        setToken457F3E65BD903C1FC8AAE(std::shared_ptr<ArakGroundhog> value) {
            this->token457F3E65BD903C1FC8AAE = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenB952619F7911BD23953BD() const {
            return tokenB952619F7911BD23953BD;
        }
        void
        setTokenB952619F7911BD23953BD(std::shared_ptr<ArakGroundhog> value) {
            this->tokenB952619F7911BD23953BD = value;
        }

        std::shared_ptr<ArakGroundhog> getToken5FB0AA57C2A4D9A752093() const {
            return token5FB0AA57C2A4D9A752093;
        }
        void
        setToken5FB0AA57C2A4D9A752093(std::shared_ptr<ArakGroundhog> value) {
            this->token5FB0AA57C2A4D9A752093 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken403A70FFCF76D500D0492() const {
            return token403A70FFCF76D500D0492;
        }
        void
        setToken403A70FFCF76D500D0492(std::shared_ptr<ArakGroundhog> value) {
            this->token403A70FFCF76D500D0492 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken2BF7F992E24CB42B8F497() const {
            return token2BF7F992E24CB42B8F497;
        }
        void
        setToken2BF7F992E24CB42B8F497(std::shared_ptr<ArakGroundhog> value) {
            this->token2BF7F992E24CB42B8F497 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenD11FB99FC582DA9D129A9() const {
            return tokenD11FB99FC582DA9D129A9;
        }
        void
        setTokenD11FB99FC582DA9D129A9(std::shared_ptr<ArakGroundhog> value) {
            this->tokenD11FB99FC582DA9D129A9 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken37F9A03CEE7D128E78F8E() const {
            return token37F9A03CEE7D128E78F8E;
        }
        void
        setToken37F9A03CEE7D128E78F8E(std::shared_ptr<ChiangMaiGoose> value) {
            this->token37F9A03CEE7D128E78F8E = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenF1AC4F490B957534BC2BA() const {
            return tokenF1AC4F490B957534BC2BA;
        }
        void
        setTokenF1AC4F490B957534BC2BA(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenF1AC4F490B957534BC2BA = value;
        }

        std::shared_ptr<Token> getTokenEE5431A399A2EA755F985() const {
            return tokenEE5431A399A2EA755F985;
        }
        void setTokenEE5431A399A2EA755F985(std::shared_ptr<Token> value) {
            this->tokenEE5431A399A2EA755F985 = value;
        }

        std::shared_ptr<Token> getToken7C7D7205D6AF7E6A35AB6() const {
            return token7C7D7205D6AF7E6A35AB6;
        }
        void setToken7C7D7205D6AF7E6A35AB6(std::shared_ptr<Token> value) {
            this->token7C7D7205D6AF7E6A35AB6 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken7FEFC21E98FBD0DE662BE() const {
            return token7FEFC21E98FBD0DE662BE;
        }
        void
        setToken7FEFC21E98FBD0DE662BE(std::shared_ptr<ChiangMaiGoose> value) {
            this->token7FEFC21E98FBD0DE662BE = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken5F4FCB0691087ABE512A6() const {
            return token5F4FCB0691087ABE512A6;
        }
        void
        setToken5F4FCB0691087ABE512A6(std::shared_ptr<ChiangMaiGoose> value) {
            this->token5F4FCB0691087ABE512A6 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken73B814D8560F9AB7FA181() const {
            return token73B814D8560F9AB7FA181;
        }
        void
        setToken73B814D8560F9AB7FA181(std::shared_ptr<ChiangMaiGoose> value) {
            this->token73B814D8560F9AB7FA181 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken1BE5802AEE0CBAB99B882() const {
            return token1BE5802AEE0CBAB99B882;
        }
        void
        setToken1BE5802AEE0CBAB99B882(std::shared_ptr<ChiangMaiGoose> value) {
            this->token1BE5802AEE0CBAB99B882 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken9F7A70A34D6F5C0FB3E88() const {
            return token9F7A70A34D6F5C0FB3E88;
        }
        void
        setToken9F7A70A34D6F5C0FB3E88(std::shared_ptr<ChiangMaiGoose> value) {
            this->token9F7A70A34D6F5C0FB3E88 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken9BBD87FF0925CB6CBA2A6() const {
            return token9BBD87FF0925CB6CBA2A6;
        }
        void
        setToken9BBD87FF0925CB6CBA2A6(std::shared_ptr<ChiangMaiGoose> value) {
            this->token9BBD87FF0925CB6CBA2A6 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE973C7D95C067E9422E89() const {
            return tokenE973C7D95C067E9422E89;
        }
        void
        setTokenE973C7D95C067E9422E89(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE973C7D95C067E9422E89 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken4A8B125DFC764AAB727A7() const {
            return token4A8B125DFC764AAB727A7;
        }
        void
        setToken4A8B125DFC764AAB727A7(std::shared_ptr<ArakGroundhog> value) {
            this->token4A8B125DFC764AAB727A7 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken05E57D99C3CD69F05C7BC() const {
            return token05E57D99C3CD69F05C7BC;
        }
        void
        setToken05E57D99C3CD69F05C7BC(std::shared_ptr<ArakGroundhog> value) {
            this->token05E57D99C3CD69F05C7BC = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenF889173B1228AC1E84FA3() const {
            return tokenF889173B1228AC1E84FA3;
        }
        void
        setTokenF889173B1228AC1E84FA3(std::shared_ptr<ArakGroundhog> value) {
            this->tokenF889173B1228AC1E84FA3 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenDD46C0D463EB26DE473B5() const {
            return tokenDD46C0D463EB26DE473B5;
        }
        void
        setTokenDD46C0D463EB26DE473B5(std::shared_ptr<ArakGroundhog> value) {
            this->tokenDD46C0D463EB26DE473B5 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE76ABAC6694B03E9CE087() const {
            return tokenE76ABAC6694B03E9CE087;
        }
        void
        setTokenE76ABAC6694B03E9CE087(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE76ABAC6694B03E9CE087 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenD28FD03E38ACE143DF1BA() const {
            return tokenD28FD03E38ACE143DF1BA;
        }
        void
        setTokenD28FD03E38ACE143DF1BA(std::shared_ptr<ArakGroundhog> value) {
            this->tokenD28FD03E38ACE143DF1BA = value;
        }

        std::shared_ptr<ArakGroundhog> getToken020A9754A3089AC08B48C() const {
            return token020A9754A3089AC08B48C;
        }
        void
        setToken020A9754A3089AC08B48C(std::shared_ptr<ArakGroundhog> value) {
            this->token020A9754A3089AC08B48C = value;
        }

        std::shared_ptr<ArakGroundhog> getToken5F5D6D55FC1A1735A8C91() const {
            return token5F5D6D55FC1A1735A8C91;
        }
        void
        setToken5F5D6D55FC1A1735A8C91(std::shared_ptr<ArakGroundhog> value) {
            this->token5F5D6D55FC1A1735A8C91 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCEA6AB430FA895B14D38C() const {
            return tokenCEA6AB430FA895B14D38C;
        }
        void
        setTokenCEA6AB430FA895B14D38C(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCEA6AB430FA895B14D38C = value;
        }

        std::shared_ptr<ArakGroundhog> getToken69F211937F19241D2719A() const {
            return token69F211937F19241D2719A;
        }
        void
        setToken69F211937F19241D2719A(std::shared_ptr<ArakGroundhog> value) {
            this->token69F211937F19241D2719A = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenB23C7403A039BD742F790() const {
            return tokenB23C7403A039BD742F790;
        }
        void
        setTokenB23C7403A039BD742F790(std::shared_ptr<ArakGroundhog> value) {
            this->tokenB23C7403A039BD742F790 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken7FFE1F12B5DE3C78BD5B3() const {
            return token7FFE1F12B5DE3C78BD5B3;
        }
        void
        setToken7FFE1F12B5DE3C78BD5B3(std::shared_ptr<ArakGroundhog> value) {
            this->token7FFE1F12B5DE3C78BD5B3 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenC2FB3EC7DD3C5A14987A4() const {
            return tokenC2FB3EC7DD3C5A14987A4;
        }
        void
        setTokenC2FB3EC7DD3C5A14987A4(std::shared_ptr<ArakGroundhog> value) {
            this->tokenC2FB3EC7DD3C5A14987A4 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken189330D6BFCA399608FB4() const {
            return token189330D6BFCA399608FB4;
        }
        void
        setToken189330D6BFCA399608FB4(std::shared_ptr<ArakGroundhog> value) {
            this->token189330D6BFCA399608FB4 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenAF767EF443126B3CCD8AF() const {
            return tokenAF767EF443126B3CCD8AF;
        }
        void
        setTokenAF767EF443126B3CCD8AF(std::shared_ptr<ArakGroundhog> value) {
            this->tokenAF767EF443126B3CCD8AF = value;
        }

        std::shared_ptr<ArakGroundhog> getToken773BE241B74FA7597F780() const {
            return token773BE241B74FA7597F780;
        }
        void
        setToken773BE241B74FA7597F780(std::shared_ptr<ArakGroundhog> value) {
            this->token773BE241B74FA7597F780 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken1BE823E3464AD53321FB1() const {
            return token1BE823E3464AD53321FB1;
        }
        void
        setToken1BE823E3464AD53321FB1(std::shared_ptr<ArakGroundhog> value) {
            this->token1BE823E3464AD53321FB1 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken5F162503444CFEC22AF81() const {
            return token5F162503444CFEC22AF81;
        }
        void
        setToken5F162503444CFEC22AF81(std::shared_ptr<ArakGroundhog> value) {
            this->token5F162503444CFEC22AF81 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken13ACDBA5AF1CC23DF99BA() const {
            return token13ACDBA5AF1CC23DF99BA;
        }
        void
        setToken13ACDBA5AF1CC23DF99BA(std::shared_ptr<ArakGroundhog> value) {
            this->token13ACDBA5AF1CC23DF99BA = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9FDF39287E87C1B324894() const {
            return token9FDF39287E87C1B324894;
        }
        void
        setToken9FDF39287E87C1B324894(std::shared_ptr<ArakGroundhog> value) {
            this->token9FDF39287E87C1B324894 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenA32E4613028FD614C2992() const {
            return tokenA32E4613028FD614C2992;
        }
        void
        setTokenA32E4613028FD614C2992(std::shared_ptr<ArakGroundhog> value) {
            this->tokenA32E4613028FD614C2992 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenA433BA409058D6BE952A5() const {
            return tokenA433BA409058D6BE952A5;
        }
        void
        setTokenA433BA409058D6BE952A5(std::shared_ptr<ArakGroundhog> value) {
            this->tokenA433BA409058D6BE952A5 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken7CF34D79E5F77AD7595B5() const {
            return token7CF34D79E5F77AD7595B5;
        }
        void
        setToken7CF34D79E5F77AD7595B5(std::shared_ptr<ArakGroundhog> value) {
            this->token7CF34D79E5F77AD7595B5 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken92B8DA5E1E3E67C80D793() const {
            return token92B8DA5E1E3E67C80D793;
        }
        void
        setToken92B8DA5E1E3E67C80D793(std::shared_ptr<ArakGroundhog> value) {
            this->token92B8DA5E1E3E67C80D793 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken75BD980A2FAC6679C9CA9() const {
            return token75BD980A2FAC6679C9CA9;
        }
        void
        setToken75BD980A2FAC6679C9CA9(std::shared_ptr<ArakGroundhog> value) {
            this->token75BD980A2FAC6679C9CA9 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken804528C0EDB6908B0B899() const {
            return token804528C0EDB6908B0B899;
        }
        void
        setToken804528C0EDB6908B0B899(std::shared_ptr<ArakGroundhog> value) {
            this->token804528C0EDB6908B0B899 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCBA976567E4283E3E9E9B() const {
            return tokenCBA976567E4283E3E9E9B;
        }
        void
        setTokenCBA976567E4283E3E9E9B(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCBA976567E4283E3E9E9B = value;
        }

        std::shared_ptr<ArakGroundhog> getToken99C6A24D2A561187A77BA() const {
            return token99C6A24D2A561187A77BA;
        }
        void
        setToken99C6A24D2A561187A77BA(std::shared_ptr<ArakGroundhog> value) {
            this->token99C6A24D2A561187A77BA = value;
        }

        std::shared_ptr<ArakGroundhog> getToken25B4946A8DC84F7E5F0AA() const {
            return token25B4946A8DC84F7E5F0AA;
        }
        void
        setToken25B4946A8DC84F7E5F0AA(std::shared_ptr<ArakGroundhog> value) {
            this->token25B4946A8DC84F7E5F0AA = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenC75FA378013EC28E08CA9() const {
            return tokenC75FA378013EC28E08CA9;
        }
        void
        setTokenC75FA378013EC28E08CA9(std::shared_ptr<ArakGroundhog> value) {
            this->tokenC75FA378013EC28E08CA9 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken4B8879991B0C58A8DE786() const {
            return token4B8879991B0C58A8DE786;
        }
        void
        setToken4B8879991B0C58A8DE786(std::shared_ptr<ArakGroundhog> value) {
            this->token4B8879991B0C58A8DE786 = value;
        }

        std::shared_ptr<Token> getToken5DC7CA1D490AB35523D9E() const {
            return token5DC7CA1D490AB35523D9E;
        }
        void setToken5DC7CA1D490AB35523D9E(std::shared_ptr<Token> value) {
            this->token5DC7CA1D490AB35523D9E = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken7D071A1FBCAE3D2EC0C90() const {
            return token7D071A1FBCAE3D2EC0C90;
        }
        void
        setToken7D071A1FBCAE3D2EC0C90(std::shared_ptr<ChiangMaiGoose> value) {
            this->token7D071A1FBCAE3D2EC0C90 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenD9214DB82A79855D1859D() const {
            return tokenD9214DB82A79855D1859D;
        }
        void
        setTokenD9214DB82A79855D1859D(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenD9214DB82A79855D1859D = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken410A7675F420C35808D87() const {
            return token410A7675F420C35808D87;
        }
        void
        setToken410A7675F420C35808D87(std::shared_ptr<ChiangMaiGoose> value) {
            this->token410A7675F420C35808D87 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenA9E0E34E0D049ABBC058C() const {
            return tokenA9E0E34E0D049ABBC058C;
        }
        void
        setTokenA9E0E34E0D049ABBC058C(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenA9E0E34E0D049ABBC058C = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken6606AC90A18517646E98C() const {
            return token6606AC90A18517646E98C;
        }
        void
        setToken6606AC90A18517646E98C(std::shared_ptr<ChiangMaiGoose> value) {
            this->token6606AC90A18517646E98C = value;
        }

        std::shared_ptr<Token31Dc1509Db328F11Ce0Ac>
        getToken31DC1509DB328F11CE0AC() const {
            return token31DC1509DB328F11CE0AC;
        }
        void setToken31DC1509DB328F11CE0AC(
            std::shared_ptr<Token31Dc1509Db328F11Ce0Ac> value) {
            this->token31DC1509DB328F11CE0AC = value;
        }

        std::shared_ptr<ArakGroundhog> getToken2257B2C2C7580FB792CA6() const {
            return token2257B2C2C7580FB792CA6;
        }
        void
        setToken2257B2C2C7580FB792CA6(std::shared_ptr<ArakGroundhog> value) {
            this->token2257B2C2C7580FB792CA6 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9DF69821A140BE2EE72A7() const {
            return token9DF69821A140BE2EE72A7;
        }
        void
        setToken9DF69821A140BE2EE72A7(std::shared_ptr<ArakGroundhog> value) {
            this->token9DF69821A140BE2EE72A7 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken73FE56D22D475C7AEDDBC() const {
            return token73FE56D22D475C7AEDDBC;
        }
        void
        setToken73FE56D22D475C7AEDDBC(std::shared_ptr<ChiangMaiGoose> value) {
            this->token73FE56D22D475C7AEDDBC = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenC5CF6A9EB1465D3AA6FB2() const {
            return tokenC5CF6A9EB1465D3AA6FB2;
        }
        void
        setTokenC5CF6A9EB1465D3AA6FB2(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenC5CF6A9EB1465D3AA6FB2 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken52486AA7D796B2255BFAC() const {
            return token52486AA7D796B2255BFAC;
        }
        void
        setToken52486AA7D796B2255BFAC(std::shared_ptr<ChiangMaiGoose> value) {
            this->token52486AA7D796B2255BFAC = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenB5C1EE76A29C4B9565FA4() const {
            return tokenB5C1EE76A29C4B9565FA4;
        }
        void
        setTokenB5C1EE76A29C4B9565FA4(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenB5C1EE76A29C4B9565FA4 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken484BB1EF60EDADE1B5F87() const {
            return token484BB1EF60EDADE1B5F87;
        }
        void
        setToken484BB1EF60EDADE1B5F87(std::shared_ptr<ChiangMaiGoose> value) {
            this->token484BB1EF60EDADE1B5F87 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenCC0C3139115704DDCD9B5() const {
            return tokenCC0C3139115704DDCD9B5;
        }
        void
        setTokenCC0C3139115704DDCD9B5(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenCC0C3139115704DDCD9B5 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenF982C7EC74EC42B045292() const {
            return tokenF982C7EC74EC42B045292;
        }
        void
        setTokenF982C7EC74EC42B045292(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenF982C7EC74EC42B045292 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE21184507C5F3D50DB6B7() const {
            return tokenE21184507C5F3D50DB6B7;
        }
        void
        setTokenE21184507C5F3D50DB6B7(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE21184507C5F3D50DB6B7 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenD45E9BEA4A13EF51DEBAA() const {
            return tokenD45E9BEA4A13EF51DEBAA;
        }
        void
        setTokenD45E9BEA4A13EF51DEBAA(std::shared_ptr<ArakGroundhog> value) {
            this->tokenD45E9BEA4A13EF51DEBAA = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenB6862EBB8098F3A7844B2() const {
            return tokenB6862EBB8098F3A7844B2;
        }
        void
        setTokenB6862EBB8098F3A7844B2(std::shared_ptr<ArakGroundhog> value) {
            this->tokenB6862EBB8098F3A7844B2 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE4172A6C64523DEA10F86() const {
            return tokenE4172A6C64523DEA10F86;
        }
        void
        setTokenE4172A6C64523DEA10F86(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE4172A6C64523DEA10F86 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenA95061722FE9A77D1DFBF() const {
            return tokenA95061722FE9A77D1DFBF;
        }
        void
        setTokenA95061722FE9A77D1DFBF(std::shared_ptr<ArakGroundhog> value) {
            this->tokenA95061722FE9A77D1DFBF = value;
        }

        std::shared_ptr<ArakGroundhog> getToken5B69AE3AA1EF011AAD4B3() const {
            return token5B69AE3AA1EF011AAD4B3;
        }
        void
        setToken5B69AE3AA1EF011AAD4B3(std::shared_ptr<ArakGroundhog> value) {
            this->token5B69AE3AA1EF011AAD4B3 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken66A3AAAD4DD83FCA1879F() const {
            return token66A3AAAD4DD83FCA1879F;
        }
        void
        setToken66A3AAAD4DD83FCA1879F(std::shared_ptr<ArakGroundhog> value) {
            this->token66A3AAAD4DD83FCA1879F = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenF8E4C5685995705F88B92() const {
            return tokenF8E4C5685995705F88B92;
        }
        void
        setTokenF8E4C5685995705F88B92(std::shared_ptr<ArakGroundhog> value) {
            this->tokenF8E4C5685995705F88B92 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenC00E691B0A55A2DD43EB8() const {
            return tokenC00E691B0A55A2DD43EB8;
        }
        void
        setTokenC00E691B0A55A2DD43EB8(std::shared_ptr<ArakGroundhog> value) {
            this->tokenC00E691B0A55A2DD43EB8 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9F9B02979A0DF3CC4778D() const {
            return token9F9B02979A0DF3CC4778D;
        }
        void
        setToken9F9B02979A0DF3CC4778D(std::shared_ptr<ArakGroundhog> value) {
            this->token9F9B02979A0DF3CC4778D = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenDC19D53DD6052509AD1A3() const {
            return tokenDC19D53DD6052509AD1A3;
        }
        void
        setTokenDC19D53DD6052509AD1A3(std::shared_ptr<ArakGroundhog> value) {
            this->tokenDC19D53DD6052509AD1A3 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken4AA54B21F152FC8DF76AF() const {
            return token4AA54B21F152FC8DF76AF;
        }
        void
        setToken4AA54B21F152FC8DF76AF(std::shared_ptr<ArakGroundhog> value) {
            this->token4AA54B21F152FC8DF76AF = value;
        }

        std::shared_ptr<ArakGroundhog> getToken0A1129926CF5AB0429CBF() const {
            return token0A1129926CF5AB0429CBF;
        }
        void
        setToken0A1129926CF5AB0429CBF(std::shared_ptr<ArakGroundhog> value) {
            this->token0A1129926CF5AB0429CBF = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenDD5788037C4E041210AA5() const {
            return tokenDD5788037C4E041210AA5;
        }
        void
        setTokenDD5788037C4E041210AA5(std::shared_ptr<ArakGroundhog> value) {
            this->tokenDD5788037C4E041210AA5 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenAD10645A4F87DE5EB0BAE() const {
            return tokenAD10645A4F87DE5EB0BAE;
        }
        void
        setTokenAD10645A4F87DE5EB0BAE(std::shared_ptr<ArakGroundhog> value) {
            this->tokenAD10645A4F87DE5EB0BAE = value;
        }

        std::shared_ptr<Token> getTokenEB8B0C94A2755E7867D88() const {
            return tokenEB8B0C94A2755E7867D88;
        }
        void setTokenEB8B0C94A2755E7867D88(std::shared_ptr<Token> value) {
            this->tokenEB8B0C94A2755E7867D88 = value;
        }

        std::shared_ptr<Token> getToken070C5B4CF3C6A0525EF8A() const {
            return token070C5B4CF3C6A0525EF8A;
        }
        void setToken070C5B4CF3C6A0525EF8A(std::shared_ptr<Token> value) {
            this->token070C5B4CF3C6A0525EF8A = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken2005A2B8966B82D1465B0() const {
            return token2005A2B8966B82D1465B0;
        }
        void
        setToken2005A2B8966B82D1465B0(std::shared_ptr<ChiangMaiGoose> value) {
            this->token2005A2B8966B82D1465B0 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenEEC2396B3AA201D183BB2() const {
            return tokenEEC2396B3AA201D183BB2;
        }
        void
        setTokenEEC2396B3AA201D183BB2(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenEEC2396B3AA201D183BB2 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken6F19EA16BAF005F8A9890() const {
            return token6F19EA16BAF005F8A9890;
        }
        void
        setToken6F19EA16BAF005F8A9890(std::shared_ptr<ChiangMaiGoose> value) {
            this->token6F19EA16BAF005F8A9890 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken6D2EAF6B75B43DAFAE6B5() const {
            return token6D2EAF6B75B43DAFAE6B5;
        }
        void
        setToken6D2EAF6B75B43DAFAE6B5(std::shared_ptr<ChiangMaiGoose> value) {
            this->token6D2EAF6B75B43DAFAE6B5 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken22D7AA24310E5C01DD7A6() const {
            return token22D7AA24310E5C01DD7A6;
        }
        void
        setToken22D7AA24310E5C01DD7A6(std::shared_ptr<ChiangMaiGoose> value) {
            this->token22D7AA24310E5C01DD7A6 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenB073BFD6F6F1A54561AAA() const {
            return tokenB073BFD6F6F1A54561AAA;
        }
        void
        setTokenB073BFD6F6F1A54561AAA(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenB073BFD6F6F1A54561AAA = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenDC4D65D0323293BD9FFBE() const {
            return tokenDC4D65D0323293BD9FFBE;
        }
        void
        setTokenDC4D65D0323293BD9FFBE(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenDC4D65D0323293BD9FFBE = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken864AD60BCF6F538F88098() const {
            return token864AD60BCF6F538F88098;
        }
        void
        setToken864AD60BCF6F538F88098(std::shared_ptr<ChiangMaiGoose> value) {
            this->token864AD60BCF6F538F88098 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken0A5BB893872F8C8C67DB9() const {
            return token0A5BB893872F8C8C67DB9;
        }
        void
        setToken0A5BB893872F8C8C67DB9(std::shared_ptr<ChiangMaiGoose> value) {
            this->token0A5BB893872F8C8C67DB9 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenBE0C2097C4F2C19F66CA2() const {
            return tokenBE0C2097C4F2C19F66CA2;
        }
        void
        setTokenBE0C2097C4F2C19F66CA2(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenBE0C2097C4F2C19F66CA2 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken4BFDDDF8D2722BCE14B9E() const {
            return token4BFDDDF8D2722BCE14B9E;
        }
        void
        setToken4BFDDDF8D2722BCE14B9E(std::shared_ptr<ArakGroundhog> value) {
            this->token4BFDDDF8D2722BCE14B9E = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenD54C011E1AB9599CC109C() const {
            return tokenD54C011E1AB9599CC109C;
        }
        void
        setTokenD54C011E1AB9599CC109C(std::shared_ptr<ArakGroundhog> value) {
            this->tokenD54C011E1AB9599CC109C = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenD98EE3E8307B8F045AFB2() const {
            return tokenD98EE3E8307B8F045AFB2;
        }
        void
        setTokenD98EE3E8307B8F045AFB2(std::shared_ptr<ArakGroundhog> value) {
            this->tokenD98EE3E8307B8F045AFB2 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenF09F92BD69607DA9FA58A() const {
            return tokenF09F92BD69607DA9FA58A;
        }
        void
        setTokenF09F92BD69607DA9FA58A(std::shared_ptr<ArakGroundhog> value) {
            this->tokenF09F92BD69607DA9FA58A = value;
        }

        std::shared_ptr<ArakGroundhog> getToken8895755EBF6C843217193() const {
            return token8895755EBF6C843217193;
        }
        void
        setToken8895755EBF6C843217193(std::shared_ptr<ArakGroundhog> value) {
            this->token8895755EBF6C843217193 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken4DAA1881652DB60C7A69D() const {
            return token4DAA1881652DB60C7A69D;
        }
        void
        setToken4DAA1881652DB60C7A69D(std::shared_ptr<ArakGroundhog> value) {
            this->token4DAA1881652DB60C7A69D = value;
        }

        std::shared_ptr<ArakGroundhog> getToken5CE56514A2C581E3548BB() const {
            return token5CE56514A2C581E3548BB;
        }
        void
        setToken5CE56514A2C581E3548BB(std::shared_ptr<ArakGroundhog> value) {
            this->token5CE56514A2C581E3548BB = value;
        }

        std::shared_ptr<ArakGroundhog> getToken5286121206A18BC880CA1() const {
            return token5286121206A18BC880CA1;
        }
        void
        setToken5286121206A18BC880CA1(std::shared_ptr<ArakGroundhog> value) {
            this->token5286121206A18BC880CA1 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken0BC3D6C3440A378947E9E() const {
            return token0BC3D6C3440A378947E9E;
        }
        void
        setToken0BC3D6C3440A378947E9E(std::shared_ptr<ArakGroundhog> value) {
            this->token0BC3D6C3440A378947E9E = value;
        }

        std::shared_ptr<ArakGroundhog> getToken1017E26B4547892961C93() const {
            return token1017E26B4547892961C93;
        }
        void
        setToken1017E26B4547892961C93(std::shared_ptr<ArakGroundhog> value) {
            this->token1017E26B4547892961C93 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenF97DBB4ABBD980541AC92() const {
            return tokenF97DBB4ABBD980541AC92;
        }
        void
        setTokenF97DBB4ABBD980541AC92(std::shared_ptr<ArakGroundhog> value) {
            this->tokenF97DBB4ABBD980541AC92 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken14FD201B1642E4F7C22AE() const {
            return token14FD201B1642E4F7C22AE;
        }
        void
        setToken14FD201B1642E4F7C22AE(std::shared_ptr<ArakGroundhog> value) {
            this->token14FD201B1642E4F7C22AE = value;
        }

        std::shared_ptr<ArakGroundhog> getToken284542EA81AA0A8F9F3BA() const {
            return token284542EA81AA0A8F9F3BA;
        }
        void
        setToken284542EA81AA0A8F9F3BA(std::shared_ptr<ArakGroundhog> value) {
            this->token284542EA81AA0A8F9F3BA = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenDD6AB438DB39A46267791() const {
            return tokenDD6AB438DB39A46267791;
        }
        void
        setTokenDD6AB438DB39A46267791(std::shared_ptr<ArakGroundhog> value) {
            this->tokenDD6AB438DB39A46267791 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken914A425A0D1A67AE16FB4() const {
            return token914A425A0D1A67AE16FB4;
        }
        void
        setToken914A425A0D1A67AE16FB4(std::shared_ptr<ArakGroundhog> value) {
            this->token914A425A0D1A67AE16FB4 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken2713B53B467F1FC0859A4() const {
            return token2713B53B467F1FC0859A4;
        }
        void
        setToken2713B53B467F1FC0859A4(std::shared_ptr<ArakGroundhog> value) {
            this->token2713B53B467F1FC0859A4 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken6AA83D1F06D61FA4B04A0() const {
            return token6AA83D1F06D61FA4B04A0;
        }
        void
        setToken6AA83D1F06D61FA4B04A0(std::shared_ptr<ArakGroundhog> value) {
            this->token6AA83D1F06D61FA4B04A0 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenEB80AFBF5ECC14E2B7A97() const {
            return tokenEB80AFBF5ECC14E2B7A97;
        }
        void
        setTokenEB80AFBF5ECC14E2B7A97(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenEB80AFBF5ECC14E2B7A97 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenBC7FA51814A6539D0E198() const {
            return tokenBC7FA51814A6539D0E198;
        }
        void
        setTokenBC7FA51814A6539D0E198(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenBC7FA51814A6539D0E198 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenF29ABE717AA237771A58D() const {
            return tokenF29ABE717AA237771A58D;
        }
        void
        setTokenF29ABE717AA237771A58D(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenF29ABE717AA237771A58D = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenABC0CCBD80F4B6A73E183() const {
            return tokenABC0CCBD80F4B6A73E183;
        }
        void
        setTokenABC0CCBD80F4B6A73E183(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenABC0CCBD80F4B6A73E183 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken91A96AB72040DB15F0889() const {
            return token91A96AB72040DB15F0889;
        }
        void
        setToken91A96AB72040DB15F0889(std::shared_ptr<ArakGroundhog> value) {
            this->token91A96AB72040DB15F0889 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken02AE741A1216657EB1EA3() const {
            return token02AE741A1216657EB1EA3;
        }
        void
        setToken02AE741A1216657EB1EA3(std::shared_ptr<ArakGroundhog> value) {
            this->token02AE741A1216657EB1EA3 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken525BAB7BA21A8C4171196() const {
            return token525BAB7BA21A8C4171196;
        }
        void
        setToken525BAB7BA21A8C4171196(std::shared_ptr<ArakGroundhog> value) {
            this->token525BAB7BA21A8C4171196 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenC3E6904C99D6546B4D1A6() const {
            return tokenC3E6904C99D6546B4D1A6;
        }
        void
        setTokenC3E6904C99D6546B4D1A6(std::shared_ptr<ArakGroundhog> value) {
            this->tokenC3E6904C99D6546B4D1A6 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken3B4A3A61505C0DAB9B296() const {
            return token3B4A3A61505C0DAB9B296;
        }
        void
        setToken3B4A3A61505C0DAB9B296(std::shared_ptr<ArakGroundhog> value) {
            this->token3B4A3A61505C0DAB9B296 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken131E682AB43965E3CD08D() const {
            return token131E682AB43965E3CD08D;
        }
        void
        setToken131E682AB43965E3CD08D(std::shared_ptr<ArakGroundhog> value) {
            this->token131E682AB43965E3CD08D = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCD041A7D69BDD9C7BE3BB() const {
            return tokenCD041A7D69BDD9C7BE3BB;
        }
        void
        setTokenCD041A7D69BDD9C7BE3BB(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCD041A7D69BDD9C7BE3BB = value;
        }

        std::shared_ptr<ArakGroundhog> getToken05947572D06DE1DB8A298() const {
            return token05947572D06DE1DB8A298;
        }
        void
        setToken05947572D06DE1DB8A298(std::shared_ptr<ArakGroundhog> value) {
            this->token05947572D06DE1DB8A298 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken40A59E33FB628C84D12A6() const {
            return token40A59E33FB628C84D12A6;
        }
        void
        setToken40A59E33FB628C84D12A6(std::shared_ptr<ArakGroundhog> value) {
            this->token40A59E33FB628C84D12A6 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken81D360AE1966FE4A13498() const {
            return token81D360AE1966FE4A13498;
        }
        void
        setToken81D360AE1966FE4A13498(std::shared_ptr<ArakGroundhog> value) {
            this->token81D360AE1966FE4A13498 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken7F4D4B46F0D3F3E6B948B() const {
            return token7F4D4B46F0D3F3E6B948B;
        }
        void
        setToken7F4D4B46F0D3F3E6B948B(std::shared_ptr<ArakGroundhog> value) {
            this->token7F4D4B46F0D3F3E6B948B = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCD527524FFFCC134E68AD() const {
            return tokenCD527524FFFCC134E68AD;
        }
        void
        setTokenCD527524FFFCC134E68AD(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCD527524FFFCC134E68AD = value;
        }

        std::shared_ptr<ArakGroundhog> getToken09331C5A2FC68D6A37C8C() const {
            return token09331C5A2FC68D6A37C8C;
        }
        void
        setToken09331C5A2FC68D6A37C8C(std::shared_ptr<ArakGroundhog> value) {
            this->token09331C5A2FC68D6A37C8C = value;
        }

        std::shared_ptr<ArakGroundhog> getToken5E8B97B8BC1CCFE672D84() const {
            return token5E8B97B8BC1CCFE672D84;
        }
        void
        setToken5E8B97B8BC1CCFE672D84(std::shared_ptr<ArakGroundhog> value) {
            this->token5E8B97B8BC1CCFE672D84 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken1919A40BACD45BF456583() const {
            return token1919A40BACD45BF456583;
        }
        void
        setToken1919A40BACD45BF456583(std::shared_ptr<ArakGroundhog> value) {
            this->token1919A40BACD45BF456583 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCF7DBB43C1BEC8B7E0583() const {
            return tokenCF7DBB43C1BEC8B7E0583;
        }
        void
        setTokenCF7DBB43C1BEC8B7E0583(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCF7DBB43C1BEC8B7E0583 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenF9E4FCCF2958D99771DB5() const {
            return tokenF9E4FCCF2958D99771DB5;
        }
        void
        setTokenF9E4FCCF2958D99771DB5(std::shared_ptr<ArakGroundhog> value) {
            this->tokenF9E4FCCF2958D99771DB5 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken6EA6D99DA254E66ECA4BF() const {
            return token6EA6D99DA254E66ECA4BF;
        }
        void
        setToken6EA6D99DA254E66ECA4BF(std::shared_ptr<ArakGroundhog> value) {
            this->token6EA6D99DA254E66ECA4BF = value;
        }

        std::shared_ptr<ArakGroundhog> getToken325C6E6F0D4C917F612AC() const {
            return token325C6E6F0D4C917F612AC;
        }
        void
        setToken325C6E6F0D4C917F612AC(std::shared_ptr<ArakGroundhog> value) {
            this->token325C6E6F0D4C917F612AC = value;
        }

        std::shared_ptr<Token> getTokenC95E7E943D1FADFDB65A2() const {
            return tokenC95E7E943D1FADFDB65A2;
        }
        void setTokenC95E7E943D1FADFDB65A2(std::shared_ptr<Token> value) {
            this->tokenC95E7E943D1FADFDB65A2 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenA930040748B7AD6919CB7() const {
            return tokenA930040748B7AD6919CB7;
        }
        void
        setTokenA930040748B7AD6919CB7(std::shared_ptr<ArakGroundhog> value) {
            this->tokenA930040748B7AD6919CB7 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken8BC82DBF7A9FF9D0E9795() const {
            return token8BC82DBF7A9FF9D0E9795;
        }
        void
        setToken8BC82DBF7A9FF9D0E9795(std::shared_ptr<ChiangMaiGoose> value) {
            this->token8BC82DBF7A9FF9D0E9795 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken2D1004923EAF1526F8C81() const {
            return token2D1004923EAF1526F8C81;
        }
        void
        setToken2D1004923EAF1526F8C81(std::shared_ptr<ChiangMaiGoose> value) {
            this->token2D1004923EAF1526F8C81 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken0C2DC1EE6F9A4340DFCA2() const {
            return token0C2DC1EE6F9A4340DFCA2;
        }
        void
        setToken0C2DC1EE6F9A4340DFCA2(std::shared_ptr<ChiangMaiGoose> value) {
            this->token0C2DC1EE6F9A4340DFCA2 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenDA8C7775F48B125F296AA() const {
            return tokenDA8C7775F48B125F296AA;
        }
        void
        setTokenDA8C7775F48B125F296AA(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenDA8C7775F48B125F296AA = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenC079D392173F6252A9B96() const {
            return tokenC079D392173F6252A9B96;
        }
        void
        setTokenC079D392173F6252A9B96(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenC079D392173F6252A9B96 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken30AAEC5419E5CFBE0619B() const {
            return token30AAEC5419E5CFBE0619B;
        }
        void
        setToken30AAEC5419E5CFBE0619B(std::shared_ptr<ChiangMaiGoose> value) {
            this->token30AAEC5419E5CFBE0619B = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken51C9117EDCCFBD4113183() const {
            return token51C9117EDCCFBD4113183;
        }
        void
        setToken51C9117EDCCFBD4113183(std::shared_ptr<ChiangMaiGoose> value) {
            this->token51C9117EDCCFBD4113183 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken1A23A0729B946F42B568D() const {
            return token1A23A0729B946F42B568D;
        }
        void
        setToken1A23A0729B946F42B568D(std::shared_ptr<ChiangMaiGoose> value) {
            this->token1A23A0729B946F42B568D = value;
        }

        std::shared_ptr<ArakGroundhog> getToken8D1C936FAD8E7FB2960A3() const {
            return token8D1C936FAD8E7FB2960A3;
        }
        void
        setToken8D1C936FAD8E7FB2960A3(std::shared_ptr<ArakGroundhog> value) {
            this->token8D1C936FAD8E7FB2960A3 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenAE13DCA77AB5E5C238D96() const {
            return tokenAE13DCA77AB5E5C238D96;
        }
        void
        setTokenAE13DCA77AB5E5C238D96(std::shared_ptr<ArakGroundhog> value) {
            this->tokenAE13DCA77AB5E5C238D96 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken965804858147E711BBDA7() const {
            return token965804858147E711BBDA7;
        }
        void
        setToken965804858147E711BBDA7(std::shared_ptr<ArakGroundhog> value) {
            this->token965804858147E711BBDA7 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCED72F9484959B5E5E8A3() const {
            return tokenCED72F9484959B5E5E8A3;
        }
        void
        setTokenCED72F9484959B5E5E8A3(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCED72F9484959B5E5E8A3 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken748E8715DE7C703B363BD() const {
            return token748E8715DE7C703B363BD;
        }
        void
        setToken748E8715DE7C703B363BD(std::shared_ptr<ArakGroundhog> value) {
            this->token748E8715DE7C703B363BD = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenC1AA59A330DD13689138B() const {
            return tokenC1AA59A330DD13689138B;
        }
        void
        setTokenC1AA59A330DD13689138B(std::shared_ptr<ArakGroundhog> value) {
            this->tokenC1AA59A330DD13689138B = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenDA38780E0D36911690096() const {
            return tokenDA38780E0D36911690096;
        }
        void
        setTokenDA38780E0D36911690096(std::shared_ptr<ArakGroundhog> value) {
            this->tokenDA38780E0D36911690096 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE9BAFFD7C98371BA1389D() const {
            return tokenE9BAFFD7C98371BA1389D;
        }
        void
        setTokenE9BAFFD7C98371BA1389D(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE9BAFFD7C98371BA1389D = value;
        }

        std::shared_ptr<ArakGroundhog> getToken4916780C4CF9BD3B22099() const {
            return token4916780C4CF9BD3B22099;
        }
        void
        setToken4916780C4CF9BD3B22099(std::shared_ptr<ArakGroundhog> value) {
            this->token4916780C4CF9BD3B22099 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken710FCFBA6F2FE3A761E99() const {
            return token710FCFBA6F2FE3A761E99;
        }
        void
        setToken710FCFBA6F2FE3A761E99(std::shared_ptr<ArakGroundhog> value) {
            this->token710FCFBA6F2FE3A761E99 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenA8B1CBDAB3AEBB9A166A2() const {
            return tokenA8B1CBDAB3AEBB9A166A2;
        }
        void
        setTokenA8B1CBDAB3AEBB9A166A2(std::shared_ptr<ArakGroundhog> value) {
            this->tokenA8B1CBDAB3AEBB9A166A2 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken71491BF388DB005F10385() const {
            return token71491BF388DB005F10385;
        }
        void
        setToken71491BF388DB005F10385(std::shared_ptr<ArakGroundhog> value) {
            this->token71491BF388DB005F10385 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken5D62DC906634BE78EFCB4() const {
            return token5D62DC906634BE78EFCB4;
        }
        void
        setToken5D62DC906634BE78EFCB4(std::shared_ptr<ArakGroundhog> value) {
            this->token5D62DC906634BE78EFCB4 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenAA104BAE32C34D8AFA1A2() const {
            return tokenAA104BAE32C34D8AFA1A2;
        }
        void
        setTokenAA104BAE32C34D8AFA1A2(std::shared_ptr<ArakGroundhog> value) {
            this->tokenAA104BAE32C34D8AFA1A2 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken6702818DD29E09D9A22A7() const {
            return token6702818DD29E09D9A22A7;
        }
        void
        setToken6702818DD29E09D9A22A7(std::shared_ptr<ArakGroundhog> value) {
            this->token6702818DD29E09D9A22A7 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken99BC3D2DE1717F82E2999() const {
            return token99BC3D2DE1717F82E2999;
        }
        void
        setToken99BC3D2DE1717F82E2999(std::shared_ptr<ArakGroundhog> value) {
            this->token99BC3D2DE1717F82E2999 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenB3E5E87E867AE2D9B27AC() const {
            return tokenB3E5E87E867AE2D9B27AC;
        }
        void
        setTokenB3E5E87E867AE2D9B27AC(std::shared_ptr<ArakGroundhog> value) {
            this->tokenB3E5E87E867AE2D9B27AC = value;
        }

        std::shared_ptr<ArakGroundhog> getToken252B7A2AD40FEA145BD85() const {
            return token252B7A2AD40FEA145BD85;
        }
        void
        setToken252B7A2AD40FEA145BD85(std::shared_ptr<ArakGroundhog> value) {
            this->token252B7A2AD40FEA145BD85 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE8FDD64E18F3710D7EE89() const {
            return tokenE8FDD64E18F3710D7EE89;
        }
        void
        setTokenE8FDD64E18F3710D7EE89(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE8FDD64E18F3710D7EE89 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenDC53EE2DE0CA847341D8B() const {
            return tokenDC53EE2DE0CA847341D8B;
        }
        void
        setTokenDC53EE2DE0CA847341D8B(std::shared_ptr<ArakGroundhog> value) {
            this->tokenDC53EE2DE0CA847341D8B = value;
        }

        std::shared_ptr<ArakGroundhog> getToken1A7FC9AA0C41A32752294() const {
            return token1A7FC9AA0C41A32752294;
        }
        void
        setToken1A7FC9AA0C41A32752294(std::shared_ptr<ArakGroundhog> value) {
            this->token1A7FC9AA0C41A32752294 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken5E258FBC355B5959040BC() const {
            return token5E258FBC355B5959040BC;
        }
        void
        setToken5E258FBC355B5959040BC(std::shared_ptr<ArakGroundhog> value) {
            this->token5E258FBC355B5959040BC = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken0676E8BC26CADB6BAD3AA() const {
            return token0676E8BC26CADB6BAD3AA;
        }
        void
        setToken0676E8BC26CADB6BAD3AA(std::shared_ptr<ChiangMaiGoose> value) {
            this->token0676E8BC26CADB6BAD3AA = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken43A0D255D3D202BDEFCB3() const {
            return token43A0D255D3D202BDEFCB3;
        }
        void
        setToken43A0D255D3D202BDEFCB3(std::shared_ptr<ChiangMaiGoose> value) {
            this->token43A0D255D3D202BDEFCB3 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken2753FA17589D44632BB9F() const {
            return token2753FA17589D44632BB9F;
        }
        void
        setToken2753FA17589D44632BB9F(std::shared_ptr<ChiangMaiGoose> value) {
            this->token2753FA17589D44632BB9F = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken72D8015C5A42F10EC718C() const {
            return token72D8015C5A42F10EC718C;
        }
        void
        setToken72D8015C5A42F10EC718C(std::shared_ptr<ChiangMaiGoose> value) {
            this->token72D8015C5A42F10EC718C = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken537662B35E180A527F7A0() const {
            return token537662B35E180A527F7A0;
        }
        void
        setToken537662B35E180A527F7A0(std::shared_ptr<ChiangMaiGoose> value) {
            this->token537662B35E180A527F7A0 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenE0E410C8AC996EB11CB85() const {
            return tokenE0E410C8AC996EB11CB85;
        }
        void
        setTokenE0E410C8AC996EB11CB85(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenE0E410C8AC996EB11CB85 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9B1067E1332C4D152B1AD() const {
            return token9B1067E1332C4D152B1AD;
        }
        void
        setToken9B1067E1332C4D152B1AD(std::shared_ptr<ArakGroundhog> value) {
            this->token9B1067E1332C4D152B1AD = value;
        }

        std::shared_ptr<ArakGroundhog> getToken1763F37EE500EF4E84E83() const {
            return token1763F37EE500EF4E84E83;
        }
        void
        setToken1763F37EE500EF4E84E83(std::shared_ptr<ArakGroundhog> value) {
            this->token1763F37EE500EF4E84E83 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCD4BEFC7BB8BD00D5A5A9() const {
            return tokenCD4BEFC7BB8BD00D5A5A9;
        }
        void
        setTokenCD4BEFC7BB8BD00D5A5A9(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCD4BEFC7BB8BD00D5A5A9 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken7A458795BD4B0D95651B7() const {
            return token7A458795BD4B0D95651B7;
        }
        void
        setToken7A458795BD4B0D95651B7(std::shared_ptr<ArakGroundhog> value) {
            this->token7A458795BD4B0D95651B7 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken59C91F284D3472DE5B08D() const {
            return token59C91F284D3472DE5B08D;
        }
        void
        setToken59C91F284D3472DE5B08D(std::shared_ptr<ArakGroundhog> value) {
            this->token59C91F284D3472DE5B08D = value;
        }

        std::shared_ptr<ArakGroundhog> getToken2F1CE8C3537D39C3B42A3() const {
            return token2F1CE8C3537D39C3B42A3;
        }
        void
        setToken2F1CE8C3537D39C3B42A3(std::shared_ptr<ArakGroundhog> value) {
            this->token2F1CE8C3537D39C3B42A3 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken0055D3A7A18B4580C8F8C() const {
            return token0055D3A7A18B4580C8F8C;
        }
        void
        setToken0055D3A7A18B4580C8F8C(std::shared_ptr<ArakGroundhog> value) {
            this->token0055D3A7A18B4580C8F8C = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE34215A0C5DCD9035DC83() const {
            return tokenE34215A0C5DCD9035DC83;
        }
        void
        setTokenE34215A0C5DCD9035DC83(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE34215A0C5DCD9035DC83 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken10D15272527BD16B97E84() const {
            return token10D15272527BD16B97E84;
        }
        void
        setToken10D15272527BD16B97E84(std::shared_ptr<ArakGroundhog> value) {
            this->token10D15272527BD16B97E84 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken0DE01F3020C5A5A702F9A() const {
            return token0DE01F3020C5A5A702F9A;
        }
        void
        setToken0DE01F3020C5A5A702F9A(std::shared_ptr<ArakGroundhog> value) {
            this->token0DE01F3020C5A5A702F9A = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9A446B4684FA2B2656ABE() const {
            return token9A446B4684FA2B2656ABE;
        }
        void
        setToken9A446B4684FA2B2656ABE(std::shared_ptr<ArakGroundhog> value) {
            this->token9A446B4684FA2B2656ABE = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCD7E5318FC7C9816CD7B0() const {
            return tokenCD7E5318FC7C9816CD7B0;
        }
        void
        setTokenCD7E5318FC7C9816CD7B0(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCD7E5318FC7C9816CD7B0 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken013C382D3D890D3B1FEA7() const {
            return token013C382D3D890D3B1FEA7;
        }
        void
        setToken013C382D3D890D3B1FEA7(std::shared_ptr<ArakGroundhog> value) {
            this->token013C382D3D890D3B1FEA7 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken845B0B9C1B8874A7C2CB6() const {
            return token845B0B9C1B8874A7C2CB6;
        }
        void
        setToken845B0B9C1B8874A7C2CB6(std::shared_ptr<ArakGroundhog> value) {
            this->token845B0B9C1B8874A7C2CB6 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenB5E715791898691F8D780() const {
            return tokenB5E715791898691F8D780;
        }
        void
        setTokenB5E715791898691F8D780(std::shared_ptr<ArakGroundhog> value) {
            this->tokenB5E715791898691F8D780 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenC159A044375814C6307A2() const {
            return tokenC159A044375814C6307A2;
        }
        void
        setTokenC159A044375814C6307A2(std::shared_ptr<ArakGroundhog> value) {
            this->tokenC159A044375814C6307A2 = value;
        }

        std::shared_ptr<Token> getToken06D8C451D01C967B2A889() const {
            return token06D8C451D01C967B2A889;
        }
        void setToken06D8C451D01C967B2A889(std::shared_ptr<Token> value) {
            this->token06D8C451D01C967B2A889 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken4947D300F5746CB9327A9() const {
            return token4947D300F5746CB9327A9;
        }
        void
        setToken4947D300F5746CB9327A9(std::shared_ptr<ChiangMaiGoose> value) {
            this->token4947D300F5746CB9327A9 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenDBC3DD3DD9962086D98B8() const {
            return tokenDBC3DD3DD9962086D98B8;
        }
        void
        setTokenDBC3DD3DD9962086D98B8(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenDBC3DD3DD9962086D98B8 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken90B46B4771085F9F64087() const {
            return token90B46B4771085F9F64087;
        }
        void
        setToken90B46B4771085F9F64087(std::shared_ptr<ChiangMaiGoose> value) {
            this->token90B46B4771085F9F64087 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenDA864C7498ED439B5D095() const {
            return tokenDA864C7498ED439B5D095;
        }
        void
        setTokenDA864C7498ED439B5D095(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenDA864C7498ED439B5D095 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken8EDE4E47E55E8945128AC() const {
            return token8EDE4E47E55E8945128AC;
        }
        void
        setToken8EDE4E47E55E8945128AC(std::shared_ptr<ChiangMaiGoose> value) {
            this->token8EDE4E47E55E8945128AC = value;
        }

        std::shared_ptr<Token> getToken4F9CEBFCB2BCB7C1F93AE() const {
            return token4F9CEBFCB2BCB7C1F93AE;
        }
        void setToken4F9CEBFCB2BCB7C1F93AE(std::shared_ptr<Token> value) {
            this->token4F9CEBFCB2BCB7C1F93AE = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenC0E5BD48806EA05D8E1B3() const {
            return tokenC0E5BD48806EA05D8E1B3;
        }
        void
        setTokenC0E5BD48806EA05D8E1B3(std::shared_ptr<ArakGroundhog> value) {
            this->tokenC0E5BD48806EA05D8E1B3 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenA713AE88B171CF6DE2584() const {
            return tokenA713AE88B171CF6DE2584;
        }
        void
        setTokenA713AE88B171CF6DE2584(std::shared_ptr<ArakGroundhog> value) {
            this->tokenA713AE88B171CF6DE2584 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken71FE836A3546F7800028F() const {
            return token71FE836A3546F7800028F;
        }
        void
        setToken71FE836A3546F7800028F(std::shared_ptr<ArakGroundhog> value) {
            this->token71FE836A3546F7800028F = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenBF85C9CB2643D2241AFBE() const {
            return tokenBF85C9CB2643D2241AFBE;
        }
        void
        setTokenBF85C9CB2643D2241AFBE(std::shared_ptr<ArakGroundhog> value) {
            this->tokenBF85C9CB2643D2241AFBE = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenED59CC7C7EBD1C981D9AD() const {
            return tokenED59CC7C7EBD1C981D9AD;
        }
        void
        setTokenED59CC7C7EBD1C981D9AD(std::shared_ptr<ArakGroundhog> value) {
            this->tokenED59CC7C7EBD1C981D9AD = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCCF87B3D65FD49EECC6A4() const {
            return tokenCCF87B3D65FD49EECC6A4;
        }
        void
        setTokenCCF87B3D65FD49EECC6A4(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCCF87B3D65FD49EECC6A4 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken238BE16B560DAFB40A8B3() const {
            return token238BE16B560DAFB40A8B3;
        }
        void
        setToken238BE16B560DAFB40A8B3(std::shared_ptr<ArakGroundhog> value) {
            this->token238BE16B560DAFB40A8B3 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken88767604C712FA84DE2B4() const {
            return token88767604C712FA84DE2B4;
        }
        void
        setToken88767604C712FA84DE2B4(std::shared_ptr<ArakGroundhog> value) {
            this->token88767604C712FA84DE2B4 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken896C4E49DF74696BBBB8E() const {
            return token896C4E49DF74696BBBB8E;
        }
        void
        setToken896C4E49DF74696BBBB8E(std::shared_ptr<ArakGroundhog> value) {
            this->token896C4E49DF74696BBBB8E = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken2884443F1CDB74F7E97A7() const {
            return token2884443F1CDB74F7E97A7;
        }
        void
        setToken2884443F1CDB74F7E97A7(std::shared_ptr<ChiangMaiGoose> value) {
            this->token2884443F1CDB74F7E97A7 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenCD0D1A32B252CB1328B9A() const {
            return tokenCD0D1A32B252CB1328B9A;
        }
        void
        setTokenCD0D1A32B252CB1328B9A(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenCD0D1A32B252CB1328B9A = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken213D74984AAA195477685() const {
            return token213D74984AAA195477685;
        }
        void
        setToken213D74984AAA195477685(std::shared_ptr<ChiangMaiGoose> value) {
            this->token213D74984AAA195477685 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken594687C9B2CA65E5CB496() const {
            return token594687C9B2CA65E5CB496;
        }
        void
        setToken594687C9B2CA65E5CB496(std::shared_ptr<ChiangMaiGoose> value) {
            this->token594687C9B2CA65E5CB496 = value;
        }

        std::shared_ptr<Token> getTokenEC6AA0C48EEA99823E1A2() const {
            return tokenEC6AA0C48EEA99823E1A2;
        }
        void setTokenEC6AA0C48EEA99823E1A2(std::shared_ptr<Token> value) {
            this->tokenEC6AA0C48EEA99823E1A2 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken896463C5DE287BB120E80() const {
            return token896463C5DE287BB120E80;
        }
        void
        setToken896463C5DE287BB120E80(std::shared_ptr<ArakGroundhog> value) {
            this->token896463C5DE287BB120E80 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenB7B473A156B5AFEF56FA3() const {
            return tokenB7B473A156B5AFEF56FA3;
        }
        void
        setTokenB7B473A156B5AFEF56FA3(std::shared_ptr<ArakGroundhog> value) {
            this->tokenB7B473A156B5AFEF56FA3 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenBA252399CE2C5F9194790() const {
            return tokenBA252399CE2C5F9194790;
        }
        void
        setTokenBA252399CE2C5F9194790(std::shared_ptr<ArakGroundhog> value) {
            this->tokenBA252399CE2C5F9194790 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenD65725A7C3014B742D999() const {
            return tokenD65725A7C3014B742D999;
        }
        void
        setTokenD65725A7C3014B742D999(std::shared_ptr<ArakGroundhog> value) {
            this->tokenD65725A7C3014B742D999 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken88AB56442BF560EA449A1() const {
            return token88AB56442BF560EA449A1;
        }
        void
        setToken88AB56442BF560EA449A1(std::shared_ptr<ArakGroundhog> value) {
            this->token88AB56442BF560EA449A1 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9E6C96FBA7639E73BCE9D() const {
            return token9E6C96FBA7639E73BCE9D;
        }
        void
        setToken9E6C96FBA7639E73BCE9D(std::shared_ptr<ArakGroundhog> value) {
            this->token9E6C96FBA7639E73BCE9D = value;
        }

        std::shared_ptr<ArakGroundhog> getToken4201CDF79A2F9160671B3() const {
            return token4201CDF79A2F9160671B3;
        }
        void
        setToken4201CDF79A2F9160671B3(std::shared_ptr<ArakGroundhog> value) {
            this->token4201CDF79A2F9160671B3 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken868303FF0484A110D1293() const {
            return token868303FF0484A110D1293;
        }
        void
        setToken868303FF0484A110D1293(std::shared_ptr<ArakGroundhog> value) {
            this->token868303FF0484A110D1293 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken85AD0DE8698EA728E5D9C() const {
            return token85AD0DE8698EA728E5D9C;
        }
        void
        setToken85AD0DE8698EA728E5D9C(std::shared_ptr<ArakGroundhog> value) {
            this->token85AD0DE8698EA728E5D9C = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenFCF78BB01006B90686088() const {
            return tokenFCF78BB01006B90686088;
        }
        void
        setTokenFCF78BB01006B90686088(std::shared_ptr<ArakGroundhog> value) {
            this->tokenFCF78BB01006B90686088 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenA2BD2B5293660FB1173A6() const {
            return tokenA2BD2B5293660FB1173A6;
        }
        void
        setTokenA2BD2B5293660FB1173A6(std::shared_ptr<ArakGroundhog> value) {
            this->tokenA2BD2B5293660FB1173A6 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken01D8ECCF9F69D3E9FC7B1() const {
            return token01D8ECCF9F69D3E9FC7B1;
        }
        void
        setToken01D8ECCF9F69D3E9FC7B1(std::shared_ptr<ArakGroundhog> value) {
            this->token01D8ECCF9F69D3E9FC7B1 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken7976D7BDB91692136A1AB() const {
            return token7976D7BDB91692136A1AB;
        }
        void
        setToken7976D7BDB91692136A1AB(std::shared_ptr<ArakGroundhog> value) {
            this->token7976D7BDB91692136A1AB = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenA86DB4585C3D45CB353AD() const {
            return tokenA86DB4585C3D45CB353AD;
        }
        void
        setTokenA86DB4585C3D45CB353AD(std::shared_ptr<ArakGroundhog> value) {
            this->tokenA86DB4585C3D45CB353AD = value;
        }

        std::shared_ptr<ArakGroundhog> getToken71EB4680E8A3A35BA0FB0() const {
            return token71EB4680E8A3A35BA0FB0;
        }
        void
        setToken71EB4680E8A3A35BA0FB0(std::shared_ptr<ArakGroundhog> value) {
            this->token71EB4680E8A3A35BA0FB0 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenEEAF0DEE6AD40E74DA5BC() const {
            return tokenEEAF0DEE6AD40E74DA5BC;
        }
        void
        setTokenEEAF0DEE6AD40E74DA5BC(std::shared_ptr<ArakGroundhog> value) {
            this->tokenEEAF0DEE6AD40E74DA5BC = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenEA6E3BE35693BB6FB8BB7() const {
            return tokenEA6E3BE35693BB6FB8BB7;
        }
        void
        setTokenEA6E3BE35693BB6FB8BB7(std::shared_ptr<ArakGroundhog> value) {
            this->tokenEA6E3BE35693BB6FB8BB7 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCEA2074211CEEBD9B5DB3() const {
            return tokenCEA2074211CEEBD9B5DB3;
        }
        void
        setTokenCEA2074211CEEBD9B5DB3(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCEA2074211CEEBD9B5DB3 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken1C733F07F13173D19B29F() const {
            return token1C733F07F13173D19B29F;
        }
        void
        setToken1C733F07F13173D19B29F(std::shared_ptr<ArakGroundhog> value) {
            this->token1C733F07F13173D19B29F = value;
        }

        std::shared_ptr<ArakGroundhog> getToken20C940B34447AB12CCEA8() const {
            return token20C940B34447AB12CCEA8;
        }
        void
        setToken20C940B34447AB12CCEA8(std::shared_ptr<ArakGroundhog> value) {
            this->token20C940B34447AB12CCEA8 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken44ABE8B7288C4D59102B5() const {
            return token44ABE8B7288C4D59102B5;
        }
        void
        setToken44ABE8B7288C4D59102B5(std::shared_ptr<ArakGroundhog> value) {
            this->token44ABE8B7288C4D59102B5 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenEEC6944070EA265B950B0() const {
            return tokenEEC6944070EA265B950B0;
        }
        void
        setTokenEEC6944070EA265B950B0(std::shared_ptr<ArakGroundhog> value) {
            this->tokenEEC6944070EA265B950B0 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken4AFD25AD6666299F2A88B() const {
            return token4AFD25AD6666299F2A88B;
        }
        void
        setToken4AFD25AD6666299F2A88B(std::shared_ptr<ArakGroundhog> value) {
            this->token4AFD25AD6666299F2A88B = value;
        }

        std::shared_ptr<ArakGroundhog> getToken6669C3AABD6369A1AED82() const {
            return token6669C3AABD6369A1AED82;
        }
        void
        setToken6669C3AABD6369A1AED82(std::shared_ptr<ArakGroundhog> value) {
            this->token6669C3AABD6369A1AED82 = value;
        }

        std::shared_ptr<Token> getToken5B280CB8A69F3D0902EA4() const {
            return token5B280CB8A69F3D0902EA4;
        }
        void setToken5B280CB8A69F3D0902EA4(std::shared_ptr<Token> value) {
            this->token5B280CB8A69F3D0902EA4 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenCDFF7828935B02B2CDF86() const {
            return tokenCDFF7828935B02B2CDF86;
        }
        void
        setTokenCDFF7828935B02B2CDF86(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenCDFF7828935B02B2CDF86 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenAF8113E8B8049BAEB73B1() const {
            return tokenAF8113E8B8049BAEB73B1;
        }
        void
        setTokenAF8113E8B8049BAEB73B1(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenAF8113E8B8049BAEB73B1 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken696B050B75268E575EE84() const {
            return token696B050B75268E575EE84;
        }
        void
        setToken696B050B75268E575EE84(std::shared_ptr<ChiangMaiGoose> value) {
            this->token696B050B75268E575EE84 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken892A51A637EF5A550FDBA() const {
            return token892A51A637EF5A550FDBA;
        }
        void
        setToken892A51A637EF5A550FDBA(std::shared_ptr<ChiangMaiGoose> value) {
            this->token892A51A637EF5A550FDBA = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken0DE090A2C87A61162BBA4() const {
            return token0DE090A2C87A61162BBA4;
        }
        void
        setToken0DE090A2C87A61162BBA4(std::shared_ptr<ChiangMaiGoose> value) {
            this->token0DE090A2C87A61162BBA4 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken63CC3A387F5BAEF69D4A7() const {
            return token63CC3A387F5BAEF69D4A7;
        }
        void
        setToken63CC3A387F5BAEF69D4A7(std::shared_ptr<ChiangMaiGoose> value) {
            this->token63CC3A387F5BAEF69D4A7 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken0B1C3C68043A4F4B61F9F() const {
            return token0B1C3C68043A4F4B61F9F;
        }
        void
        setToken0B1C3C68043A4F4B61F9F(std::shared_ptr<ChiangMaiGoose> value) {
            this->token0B1C3C68043A4F4B61F9F = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken0A4486D1E21D43E961BA6() const {
            return token0A4486D1E21D43E961BA6;
        }
        void
        setToken0A4486D1E21D43E961BA6(std::shared_ptr<ChiangMaiGoose> value) {
            this->token0A4486D1E21D43E961BA6 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken5282457FF22ABFDE400B4() const {
            return token5282457FF22ABFDE400B4;
        }
        void
        setToken5282457FF22ABFDE400B4(std::shared_ptr<ChiangMaiGoose> value) {
            this->token5282457FF22ABFDE400B4 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenD8774B9492D7CBFC37CB8() const {
            return tokenD8774B9492D7CBFC37CB8;
        }
        void
        setTokenD8774B9492D7CBFC37CB8(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenD8774B9492D7CBFC37CB8 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken4B5D845A389A0EE19AABF() const {
            return token4B5D845A389A0EE19AABF;
        }
        void
        setToken4B5D845A389A0EE19AABF(std::shared_ptr<ArakGroundhog> value) {
            this->token4B5D845A389A0EE19AABF = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE6D5489CE13AD84D8E7B7() const {
            return tokenE6D5489CE13AD84D8E7B7;
        }
        void
        setTokenE6D5489CE13AD84D8E7B7(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE6D5489CE13AD84D8E7B7 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9FF026A883F738C0B0CB9() const {
            return token9FF026A883F738C0B0CB9;
        }
        void
        setToken9FF026A883F738C0B0CB9(std::shared_ptr<ArakGroundhog> value) {
            this->token9FF026A883F738C0B0CB9 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCA96E1DBD4F7E72EED48D() const {
            return tokenCA96E1DBD4F7E72EED48D;
        }
        void
        setTokenCA96E1DBD4F7E72EED48D(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCA96E1DBD4F7E72EED48D = value;
        }

        std::shared_ptr<ArakGroundhog> getToken0D2CB48596748A6B4BFBA() const {
            return token0D2CB48596748A6B4BFBA;
        }
        void
        setToken0D2CB48596748A6B4BFBA(std::shared_ptr<ArakGroundhog> value) {
            this->token0D2CB48596748A6B4BFBA = value;
        }

        std::shared_ptr<ArakGroundhog> getToken434F3160A979CA1009882() const {
            return token434F3160A979CA1009882;
        }
        void
        setToken434F3160A979CA1009882(std::shared_ptr<ArakGroundhog> value) {
            this->token434F3160A979CA1009882 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9220F57D2902D463A1A8D() const {
            return token9220F57D2902D463A1A8D;
        }
        void
        setToken9220F57D2902D463A1A8D(std::shared_ptr<ArakGroundhog> value) {
            this->token9220F57D2902D463A1A8D = value;
        }

        std::shared_ptr<ArakGroundhog> getToken096809C9884ED117FB9B6() const {
            return token096809C9884ED117FB9B6;
        }
        void
        setToken096809C9884ED117FB9B6(std::shared_ptr<ArakGroundhog> value) {
            this->token096809C9884ED117FB9B6 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken0189CF14C1ABB9E38D288() const {
            return token0189CF14C1ABB9E38D288;
        }
        void
        setToken0189CF14C1ABB9E38D288(std::shared_ptr<ArakGroundhog> value) {
            this->token0189CF14C1ABB9E38D288 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenB044BAAF3986B432AE7BF() const {
            return tokenB044BAAF3986B432AE7BF;
        }
        void
        setTokenB044BAAF3986B432AE7BF(std::shared_ptr<ArakGroundhog> value) {
            this->tokenB044BAAF3986B432AE7BF = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenB7FA499A68198D093D8A2() const {
            return tokenB7FA499A68198D093D8A2;
        }
        void
        setTokenB7FA499A68198D093D8A2(std::shared_ptr<ArakGroundhog> value) {
            this->tokenB7FA499A68198D093D8A2 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken438FF67AE1F17D825FAB5() const {
            return token438FF67AE1F17D825FAB5;
        }
        void
        setToken438FF67AE1F17D825FAB5(std::shared_ptr<ArakGroundhog> value) {
            this->token438FF67AE1F17D825FAB5 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken352D769B1B3BB61DBAFBB() const {
            return token352D769B1B3BB61DBAFBB;
        }
        void
        setToken352D769B1B3BB61DBAFBB(std::shared_ptr<ArakGroundhog> value) {
            this->token352D769B1B3BB61DBAFBB = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenB0F4CB473A8FDBB9CE692() const {
            return tokenB0F4CB473A8FDBB9CE692;
        }
        void
        setTokenB0F4CB473A8FDBB9CE692(std::shared_ptr<ArakGroundhog> value) {
            this->tokenB0F4CB473A8FDBB9CE692 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCF772D023E3AFAE164899() const {
            return tokenCF772D023E3AFAE164899;
        }
        void
        setTokenCF772D023E3AFAE164899(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCF772D023E3AFAE164899 = value;
        }

        std::shared_ptr<Token> getTokenEC7A4FC879CE357C2DF84() const {
            return tokenEC7A4FC879CE357C2DF84;
        }
        void setTokenEC7A4FC879CE357C2DF84(std::shared_ptr<Token> value) {
            this->tokenEC7A4FC879CE357C2DF84 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken089FB68037C80FE98FCAA() const {
            return token089FB68037C80FE98FCAA;
        }
        void
        setToken089FB68037C80FE98FCAA(std::shared_ptr<ArakGroundhog> value) {
            this->token089FB68037C80FE98FCAA = value;
        }

        std::shared_ptr<ArakGroundhog> getToken346CF28DB5A65D132898E() const {
            return token346CF28DB5A65D132898E;
        }
        void
        setToken346CF28DB5A65D132898E(std::shared_ptr<ArakGroundhog> value) {
            this->token346CF28DB5A65D132898E = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenDA48586079FD76F4A9FAD() const {
            return tokenDA48586079FD76F4A9FAD;
        }
        void
        setTokenDA48586079FD76F4A9FAD(std::shared_ptr<ArakGroundhog> value) {
            this->tokenDA48586079FD76F4A9FAD = value;
        }

        std::shared_ptr<ArakGroundhog> getToken947AF2755679C774793BA() const {
            return token947AF2755679C774793BA;
        }
        void
        setToken947AF2755679C774793BA(std::shared_ptr<ArakGroundhog> value) {
            this->token947AF2755679C774793BA = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenF07D4E665D02F4187439E() const {
            return tokenF07D4E665D02F4187439E;
        }
        void
        setTokenF07D4E665D02F4187439E(std::shared_ptr<ArakGroundhog> value) {
            this->tokenF07D4E665D02F4187439E = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9E429B12B9261F6A8A489() const {
            return token9E429B12B9261F6A8A489;
        }
        void
        setToken9E429B12B9261F6A8A489(std::shared_ptr<ArakGroundhog> value) {
            this->token9E429B12B9261F6A8A489 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenE87D96060B9E2D539DC9B() const {
            return tokenE87D96060B9E2D539DC9B;
        }
        void
        setTokenE87D96060B9E2D539DC9B(std::shared_ptr<ArakGroundhog> value) {
            this->tokenE87D96060B9E2D539DC9B = value;
        }

        std::shared_ptr<ArakGroundhog> getToken0FA39B41B19A62959098F() const {
            return token0FA39B41B19A62959098F;
        }
        void
        setToken0FA39B41B19A62959098F(std::shared_ptr<ArakGroundhog> value) {
            this->token0FA39B41B19A62959098F = value;
        }

        std::shared_ptr<ArakGroundhog> getToken1803E0AC70A0D57BBA981() const {
            return token1803E0AC70A0D57BBA981;
        }
        void
        setToken1803E0AC70A0D57BBA981(std::shared_ptr<ArakGroundhog> value) {
            this->token1803E0AC70A0D57BBA981 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken48A9BB431CC7D43FD5BA8() const {
            return token48A9BB431CC7D43FD5BA8;
        }
        void
        setToken48A9BB431CC7D43FD5BA8(std::shared_ptr<ArakGroundhog> value) {
            this->token48A9BB431CC7D43FD5BA8 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenD8AC4F4104AD455C85A84() const {
            return tokenD8AC4F4104AD455C85A84;
        }
        void
        setTokenD8AC4F4104AD455C85A84(std::shared_ptr<ArakGroundhog> value) {
            this->tokenD8AC4F4104AD455C85A84 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenBF1DEF94AAFC697A6F9BA() const {
            return tokenBF1DEF94AAFC697A6F9BA;
        }
        void
        setTokenBF1DEF94AAFC697A6F9BA(std::shared_ptr<ArakGroundhog> value) {
            this->tokenBF1DEF94AAFC697A6F9BA = value;
        }

        std::shared_ptr<ArakGroundhog> getToken7D08480AD0B453BE029A8() const {
            return token7D08480AD0B453BE029A8;
        }
        void
        setToken7D08480AD0B453BE029A8(std::shared_ptr<ArakGroundhog> value) {
            this->token7D08480AD0B453BE029A8 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken4473A490C2ECEA90DAAB2() const {
            return token4473A490C2ECEA90DAAB2;
        }
        void
        setToken4473A490C2ECEA90DAAB2(std::shared_ptr<ArakGroundhog> value) {
            this->token4473A490C2ECEA90DAAB2 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenB17711FF64A6F6F06299D() const {
            return tokenB17711FF64A6F6F06299D;
        }
        void
        setTokenB17711FF64A6F6F06299D(std::shared_ptr<ArakGroundhog> value) {
            this->tokenB17711FF64A6F6F06299D = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken844BFDA4BE916BD54A3AA() const {
            return token844BFDA4BE916BD54A3AA;
        }
        void
        setToken844BFDA4BE916BD54A3AA(std::shared_ptr<ChiangMaiGoose> value) {
            this->token844BFDA4BE916BD54A3AA = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken23229682C74347EEB8886() const {
            return token23229682C74347EEB8886;
        }
        void
        setToken23229682C74347EEB8886(std::shared_ptr<ChiangMaiGoose> value) {
            this->token23229682C74347EEB8886 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken60E6C57473CB0C88A3E86() const {
            return token60E6C57473CB0C88A3E86;
        }
        void
        setToken60E6C57473CB0C88A3E86(std::shared_ptr<ChiangMaiGoose> value) {
            this->token60E6C57473CB0C88A3E86 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken8C31165AE39E790CCD7B8() const {
            return token8C31165AE39E790CCD7B8;
        }
        void
        setToken8C31165AE39E790CCD7B8(std::shared_ptr<ChiangMaiGoose> value) {
            this->token8C31165AE39E790CCD7B8 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenFE355BF81FC13A6A0DDAE() const {
            return tokenFE355BF81FC13A6A0DDAE;
        }
        void
        setTokenFE355BF81FC13A6A0DDAE(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenFE355BF81FC13A6A0DDAE = value;
        }

        std::shared_ptr<Token> getTokenCF3855D906085F5BBFB8B() const {
            return tokenCF3855D906085F5BBFB8B;
        }
        void setTokenCF3855D906085F5BBFB8B(std::shared_ptr<Token> value) {
            this->tokenCF3855D906085F5BBFB8B = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken9F00C7C0F02FB6B6BDB80() const {
            return token9F00C7C0F02FB6B6BDB80;
        }
        void
        setToken9F00C7C0F02FB6B6BDB80(std::shared_ptr<ChiangMaiGoose> value) {
            this->token9F00C7C0F02FB6B6BDB80 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken672CC221DCD193EEA0093() const {
            return token672CC221DCD193EEA0093;
        }
        void
        setToken672CC221DCD193EEA0093(std::shared_ptr<ChiangMaiGoose> value) {
            this->token672CC221DCD193EEA0093 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken682906AC7B7E242CFC883() const {
            return token682906AC7B7E242CFC883;
        }
        void
        setToken682906AC7B7E242CFC883(std::shared_ptr<ChiangMaiGoose> value) {
            this->token682906AC7B7E242CFC883 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken3D725B01FB7B9FA90E387() const {
            return token3D725B01FB7B9FA90E387;
        }
        void
        setToken3D725B01FB7B9FA90E387(std::shared_ptr<ChiangMaiGoose> value) {
            this->token3D725B01FB7B9FA90E387 = value;
        }

        std::shared_ptr<Token> getToken6A8D9E562B7D9BCC22487() const {
            return token6A8D9E562B7D9BCC22487;
        }
        void setToken6A8D9E562B7D9BCC22487(std::shared_ptr<Token> value) {
            this->token6A8D9E562B7D9BCC22487 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenFCFD60AF5972635E239A1() const {
            return tokenFCFD60AF5972635E239A1;
        }
        void
        setTokenFCFD60AF5972635E239A1(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenFCFD60AF5972635E239A1 = value;
        }

        std::shared_ptr<ChiangMaiGoose> getToken44257D2BB1EB83445748B() const {
            return token44257D2BB1EB83445748B;
        }
        void
        setToken44257D2BB1EB83445748B(std::shared_ptr<ChiangMaiGoose> value) {
            this->token44257D2BB1EB83445748B = value;
        }

        std::shared_ptr<ChiangMaiGoose> getTokenC081C1B31AD23306729BC() const {
            return tokenC081C1B31AD23306729BC;
        }
        void
        setTokenC081C1B31AD23306729BC(std::shared_ptr<ChiangMaiGoose> value) {
            this->tokenC081C1B31AD23306729BC = value;
        }

        std::shared_ptr<ArakGroundhog> getToken91EE07D52D132C0291AA9() const {
            return token91EE07D52D132C0291AA9;
        }
        void
        setToken91EE07D52D132C0291AA9(std::shared_ptr<ArakGroundhog> value) {
            this->token91EE07D52D132C0291AA9 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken463C9F3509B4B3CE21890() const {
            return token463C9F3509B4B3CE21890;
        }
        void
        setToken463C9F3509B4B3CE21890(std::shared_ptr<ArakGroundhog> value) {
            this->token463C9F3509B4B3CE21890 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenA8AE1C4637E3977ED139C() const {
            return tokenA8AE1C4637E3977ED139C;
        }
        void
        setTokenA8AE1C4637E3977ED139C(std::shared_ptr<ArakGroundhog> value) {
            this->tokenA8AE1C4637E3977ED139C = value;
        }

        std::shared_ptr<ArakGroundhog> getToken072340E8F68E6230FB595() const {
            return token072340E8F68E6230FB595;
        }
        void
        setToken072340E8F68E6230FB595(std::shared_ptr<ArakGroundhog> value) {
            this->token072340E8F68E6230FB595 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenAFEABC74E014E1FDCA189() const {
            return tokenAFEABC74E014E1FDCA189;
        }
        void
        setTokenAFEABC74E014E1FDCA189(std::shared_ptr<ArakGroundhog> value) {
            this->tokenAFEABC74E014E1FDCA189 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken8C03099B0BF7559E4CC8B() const {
            return token8C03099B0BF7559E4CC8B;
        }
        void
        setToken8C03099B0BF7559E4CC8B(std::shared_ptr<ArakGroundhog> value) {
            this->token8C03099B0BF7559E4CC8B = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenCAD830A007BF99AE22588() const {
            return tokenCAD830A007BF99AE22588;
        }
        void
        setTokenCAD830A007BF99AE22588(std::shared_ptr<ArakGroundhog> value) {
            this->tokenCAD830A007BF99AE22588 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken803EDA85AD6E2152498B9() const {
            return token803EDA85AD6E2152498B9;
        }
        void
        setToken803EDA85AD6E2152498B9(std::shared_ptr<ArakGroundhog> value) {
            this->token803EDA85AD6E2152498B9 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken261F79B544B15F18D90BC() const {
            return token261F79B544B15F18D90BC;
        }
        void
        setToken261F79B544B15F18D90BC(std::shared_ptr<ArakGroundhog> value) {
            this->token261F79B544B15F18D90BC = value;
        }

        std::shared_ptr<ArakGroundhog> getToken57FF4186B72441359A28C() const {
            return token57FF4186B72441359A28C;
        }
        void
        setToken57FF4186B72441359A28C(std::shared_ptr<ArakGroundhog> value) {
            this->token57FF4186B72441359A28C = value;
        }

        std::shared_ptr<ArakGroundhog> getToken9636866E27CE8589EBCAF() const {
            return token9636866E27CE8589EBCAF;
        }
        void
        setToken9636866E27CE8589EBCAF(std::shared_ptr<ArakGroundhog> value) {
            this->token9636866E27CE8589EBCAF = value;
        }

        std::shared_ptr<ArakGroundhog> getToken0651D7AAA332194B08DBE() const {
            return token0651D7AAA332194B08DBE;
        }
        void
        setToken0651D7AAA332194B08DBE(std::shared_ptr<ArakGroundhog> value) {
            this->token0651D7AAA332194B08DBE = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenA158381332191727F40AB() const {
            return tokenA158381332191727F40AB;
        }
        void
        setTokenA158381332191727F40AB(std::shared_ptr<ArakGroundhog> value) {
            this->tokenA158381332191727F40AB = value;
        }

        std::shared_ptr<ArakGroundhog> getToken7D115BFFC746C4DE901B1() const {
            return token7D115BFFC746C4DE901B1;
        }
        void
        setToken7D115BFFC746C4DE901B1(std::shared_ptr<ArakGroundhog> value) {
            this->token7D115BFFC746C4DE901B1 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenDCEC566E79614AE22F599() const {
            return tokenDCEC566E79614AE22F599;
        }
        void
        setTokenDCEC566E79614AE22F599(std::shared_ptr<ArakGroundhog> value) {
            this->tokenDCEC566E79614AE22F599 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenD7ECF91124B8871B9D484() const {
            return tokenD7ECF91124B8871B9D484;
        }
        void
        setTokenD7ECF91124B8871B9D484(std::shared_ptr<ArakGroundhog> value) {
            this->tokenD7ECF91124B8871B9D484 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken97EFEDD8F2A074CEAAE88() const {
            return token97EFEDD8F2A074CEAAE88;
        }
        void
        setToken97EFEDD8F2A074CEAAE88(std::shared_ptr<ArakGroundhog> value) {
            this->token97EFEDD8F2A074CEAAE88 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken3E9C3D0C2A9A1151B7B88() const {
            return token3E9C3D0C2A9A1151B7B88;
        }
        void
        setToken3E9C3D0C2A9A1151B7B88(std::shared_ptr<ArakGroundhog> value) {
            this->token3E9C3D0C2A9A1151B7B88 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken39AC0A81B17950CF2D2B5() const {
            return token39AC0A81B17950CF2D2B5;
        }
        void
        setToken39AC0A81B17950CF2D2B5(std::shared_ptr<ArakGroundhog> value) {
            this->token39AC0A81B17950CF2D2B5 = value;
        }

        std::shared_ptr<ArakGroundhog> getTokenAEC432518E3CF5FDE4FB5() const {
            return tokenAEC432518E3CF5FDE4FB5;
        }
        void
        setTokenAEC432518E3CF5FDE4FB5(std::shared_ptr<ArakGroundhog> value) {
            this->tokenAEC432518E3CF5FDE4FB5 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken5A9C312E1F012AE978784() const {
            return token5A9C312E1F012AE978784;
        }
        void
        setToken5A9C312E1F012AE978784(std::shared_ptr<ArakGroundhog> value) {
            this->token5A9C312E1F012AE978784 = value;
        }

        std::shared_ptr<Token> getTokenFBD4128927E1E68A54A81() const {
            return tokenFBD4128927E1E68A54A81;
        }
        void setTokenFBD4128927E1E68A54A81(std::shared_ptr<Token> value) {
            this->tokenFBD4128927E1E68A54A81 = value;
        }

        std::shared_ptr<ArakGroundhog> getToken910E582093166C1D0DF80() const {
            return token910E582093166C1D0DF80;
        }
        void
        setToken910E582093166C1D0DF80(std::shared_ptr<ArakGroundhog> value) {
            this->token910E582093166C1D0DF80 = value;
        }
    };

    enum class AwayType : int { ARTICLE };

    class RecapAway {
      public:
        RecapAway() = default;
        virtual ~RecapAway() = default;

      private:
        AwayType type;
        State state;
        std::string date;
        std::string id;
        std::string headline;
        std::string subhead;
        std::string seoTitle;
        std::string seoKeywords;
        std::string seoDescription;
        std::string slug;
        bool commenting;
        Photo photo;
        Image image;
        TokenData tokenData;
        std::string blurb;
        std::string body;
        AwayContributor contributor;
        std::vector<Keywords> keywordsDisplay;
        std::vector<Keywords> keywordsAll;
        std::string approval;
        std::string canonical;
        std::string dataURI;
        GameNotes primaryKeyword;
        GameNotes media;

      public:
        const AwayType &getType() const { return type; }
        AwayType &getMutableType() { return type; }
        void setType(const AwayType &value) { this->type = value; }

        const State &getState() const { return state; }
        State &getMutableState() { return state; }
        void setState(const State &value) { this->state = value; }

        const std::string &getDate() const { return date; }
        std::string &getMutableDate() { return date; }
        void setDate(const std::string &value) { this->date = value; }

        const std::string &getID() const { return id; }
        std::string &getMutableID() { return id; }
        void setID(const std::string &value) { this->id = value; }

        const std::string &getHeadline() const { return headline; }
        std::string &getMutableHeadline() { return headline; }
        void setHeadline(const std::string &value) { this->headline = value; }

        const std::string &getSubhead() const { return subhead; }
        std::string &getMutableSubhead() { return subhead; }
        void setSubhead(const std::string &value) { this->subhead = value; }

        const std::string &getSEOTitle() const { return seoTitle; }
        std::string &getMutableSEOTitle() { return seoTitle; }
        void setSEOTitle(const std::string &value) { this->seoTitle = value; }

        const std::string &getSEOKeywords() const { return seoKeywords; }
        std::string &getMutableSEOKeywords() { return seoKeywords; }
        void setSEOKeywords(const std::string &value) {
            this->seoKeywords = value;
        }

        const std::string &getSEODescription() const { return seoDescription; }
        std::string &getMutableSEODescription() { return seoDescription; }
        void setSEODescription(const std::string &value) {
            this->seoDescription = value;
        }

        const std::string &getSlug() const { return slug; }
        std::string &getMutableSlug() { return slug; }
        void setSlug(const std::string &value) { this->slug = value; }

        const bool &getCommenting() const { return commenting; }
        bool &getMutableCommenting() { return commenting; }
        void setCommenting(const bool &value) { this->commenting = value; }

        const Photo &getPhoto() const { return photo; }
        Photo &getMutablePhoto() { return photo; }
        void setPhoto(const Photo &value) { this->photo = value; }

        const Image &getImage() const { return image; }
        Image &getMutableImage() { return image; }
        void setImage(const Image &value) { this->image = value; }

        const TokenData &getTokenData() const { return tokenData; }
        TokenData &getMutableTokenData() { return tokenData; }
        void setTokenData(const TokenData &value) { this->tokenData = value; }

        const std::string &getBlurb() const { return blurb; }
        std::string &getMutableBlurb() { return blurb; }
        void setBlurb(const std::string &value) { this->blurb = value; }

        const std::string &getBody() const { return body; }
        std::string &getMutableBody() { return body; }
        void setBody(const std::string &value) { this->body = value; }

        const AwayContributor &getContributor() const { return contributor; }
        AwayContributor &getMutableContributor() { return contributor; }
        void setContributor(const AwayContributor &value) {
            this->contributor = value;
        }

        const std::vector<Keywords> &getKeywordsDisplay() const {
            return keywordsDisplay;
        }
        std::vector<Keywords> &getMutableKeywordsDisplay() {
            return keywordsDisplay;
        }
        void setKeywordsDisplay(const std::vector<Keywords> &value) {
            this->keywordsDisplay = value;
        }

        const std::vector<Keywords> &getKeywordsAll() const {
            return keywordsAll;
        }
        std::vector<Keywords> &getMutableKeywordsAll() { return keywordsAll; }
        void setKeywordsAll(const std::vector<Keywords> &value) {
            this->keywordsAll = value;
        }

        const std::string &getApproval() const { return approval; }
        std::string &getMutableApproval() { return approval; }
        void setApproval(const std::string &value) { this->approval = value; }

        const std::string &getCanonical() const { return canonical; }
        std::string &getMutableCanonical() { return canonical; }
        void setCanonical(const std::string &value) { this->canonical = value; }

        const std::string &getDataURI() const { return dataURI; }
        std::string &getMutableDataURI() { return dataURI; }
        void setDataURI(const std::string &value) { this->dataURI = value; }

        const GameNotes &getPrimaryKeyword() const { return primaryKeyword; }
        GameNotes &getMutablePrimaryKeyword() { return primaryKeyword; }
        void setPrimaryKeyword(const GameNotes &value) {
            this->primaryKeyword = value;
        }

        const GameNotes &getMedia() const { return media; }
        GameNotes &getMutableMedia() { return media; }
        void setMedia(const GameNotes &value) { this->media = value; }
    };

    enum class Language : int { EN };

    enum class MediaState : int { MEDIA_ARCHIVE };

    enum class Name : int {
        FLASH_1200_K_640_X360,
        FLASH_1800_K_960_X540,
        FLASH_2500_K_1280_X720,
        FLASH_450_K_400_X224,
        HTTP_CLOUD_ANDROID_TABLET,
        HTTP_CLOUD_MOBILE,
        HTTP_CLOUD_TABLET,
        HTTP_CLOUD_TABLET_60,
        HTTP_CLOUD_WIRED,
        HTTP_CLOUD_WIRED_60,
        HTTP_CLOUD_WIRED_WEB
    };

    class Playback {
      public:
        Playback() = default;
        virtual ~Playback() = default;

      private:
        Name name;
        std::string width;
        std::string height;
        std::string url;

      public:
        const Name &getName() const { return name; }
        Name &getMutableName() { return name; }
        void setName(const Name &value) { this->name = value; }

        const std::string &getWidth() const { return width; }
        std::string &getMutableWidth() { return width; }
        void setWidth(const std::string &value) { this->width = value; }

        const std::string &getHeight() const { return height; }
        std::string &getMutableHeight() { return height; }
        void setHeight(const std::string &value) { this->height = value; }

        const std::string &getURL() const { return url; }
        std::string &getMutableURL() { return url; }
        void setURL(const std::string &value) { this->url = value; }
    };

    class MlbMedia {
      public:
        MlbMedia() = default;
        virtual ~MlbMedia() = default;

      private:
        FluffyType type;
        State state;
        DateEnum date;
        std::string id;
        std::string topicID;
        bool noIndex;
        std::string mediaPlaybackID;
        std::string title;
        std::string headline;
        std::string kicker;
        std::string blurb;
        std::string description;
        std::string slug;
        std::string seoTitle;
        bool authFlow;
        std::string duration;
        Language language;
        MediaState mediaState;
        std::string guid;
        Image image;
        std::vector<Keywords> keywordsDisplay;
        std::vector<Keywords> keywordsAll;
        std::string mediaPlaybackURL;
        std::vector<Playback> playbacks;

      public:
        const FluffyType &getType() const { return type; }
        FluffyType &getMutableType() { return type; }
        void setType(const FluffyType &value) { this->type = value; }

        const State &getState() const { return state; }
        State &getMutableState() { return state; }
        void setState(const State &value) { this->state = value; }

        const DateEnum &getDate() const { return date; }
        DateEnum &getMutableDate() { return date; }
        void setDate(const DateEnum &value) { this->date = value; }

        const std::string &getID() const { return id; }
        std::string &getMutableID() { return id; }
        void setID(const std::string &value) { this->id = value; }

        const std::string &getTopicID() const { return topicID; }
        std::string &getMutableTopicID() { return topicID; }
        void setTopicID(const std::string &value) { this->topicID = value; }

        const bool &getNoIndex() const { return noIndex; }
        bool &getMutableNoIndex() { return noIndex; }
        void setNoIndex(const bool &value) { this->noIndex = value; }

        const std::string &getMediaPlaybackID() const {
            return mediaPlaybackID;
        }
        std::string &getMutableMediaPlaybackID() { return mediaPlaybackID; }
        void setMediaPlaybackID(const std::string &value) {
            this->mediaPlaybackID = value;
        }

        const std::string &getTitle() const { return title; }
        std::string &getMutableTitle() { return title; }
        void setTitle(const std::string &value) { this->title = value; }

        const std::string &getHeadline() const { return headline; }
        std::string &getMutableHeadline() { return headline; }
        void setHeadline(const std::string &value) { this->headline = value; }

        const std::string &getKicker() const { return kicker; }
        std::string &getMutableKicker() { return kicker; }
        void setKicker(const std::string &value) { this->kicker = value; }

        const std::string &getBlurb() const { return blurb; }
        std::string &getMutableBlurb() { return blurb; }
        void setBlurb(const std::string &value) { this->blurb = value; }

        const std::string &getDescription() const { return description; }
        std::string &getMutableDescription() { return description; }
        void setDescription(const std::string &value) {
            this->description = value;
        }

        const std::string &getSlug() const { return slug; }
        std::string &getMutableSlug() { return slug; }
        void setSlug(const std::string &value) { this->slug = value; }

        const std::string &getSEOTitle() const { return seoTitle; }
        std::string &getMutableSEOTitle() { return seoTitle; }
        void setSEOTitle(const std::string &value) { this->seoTitle = value; }

        const bool &getAuthFlow() const { return authFlow; }
        bool &getMutableAuthFlow() { return authFlow; }
        void setAuthFlow(const bool &value) { this->authFlow = value; }

        const std::string &getDuration() const { return duration; }
        std::string &getMutableDuration() { return duration; }
        void setDuration(const std::string &value) { this->duration = value; }

        const Language &getLanguage() const { return language; }
        Language &getMutableLanguage() { return language; }
        void setLanguage(const Language &value) { this->language = value; }

        const MediaState &getMediaState() const { return mediaState; }
        MediaState &getMutableMediaState() { return mediaState; }
        void setMediaState(const MediaState &value) {
            this->mediaState = value;
        }

        const std::string &getGUID() const { return guid; }
        std::string &getMutableGUID() { return guid; }
        void setGUID(const std::string &value) { this->guid = value; }

        const Image &getImage() const { return image; }
        Image &getMutableImage() { return image; }
        void setImage(const Image &value) { this->image = value; }

        const std::vector<Keywords> &getKeywordsDisplay() const {
            return keywordsDisplay;
        }
        std::vector<Keywords> &getMutableKeywordsDisplay() {
            return keywordsDisplay;
        }
        void setKeywordsDisplay(const std::vector<Keywords> &value) {
            this->keywordsDisplay = value;
        }

        const std::vector<Keywords> &getKeywordsAll() const {
            return keywordsAll;
        }
        std::vector<Keywords> &getMutableKeywordsAll() { return keywordsAll; }
        void setKeywordsAll(const std::vector<Keywords> &value) {
            this->keywordsAll = value;
        }

        const std::string &getMediaPlaybackURL() const {
            return mediaPlaybackURL;
        }
        std::string &getMutableMediaPlaybackURL() { return mediaPlaybackURL; }
        void setMediaPlaybackURL(const std::string &value) {
            this->mediaPlaybackURL = value;
        }

        const std::vector<Playback> &getPlaybacks() const { return playbacks; }
        std::vector<Playback> &getMutablePlaybacks() { return playbacks; }
        void setPlaybacks(const std::vector<Playback> &value) {
            this->playbacks = value;
        }
    };

    class Mlb {
      public:
        Mlb() = default;
        virtual ~Mlb() = default;

      private:
        AwayType type;
        State state;
        std::string date;
        std::string id;
        std::string headline;
        std::string subhead;
        std::string seoTitle;
        std::string seoKeywords;
        std::string seoDescription;
        std::string slug;
        bool commenting;
        Photo photo;
        Image image;
        TokenData tokenData;
        std::string blurb;
        std::string body;
        AwayContributor contributor;
        std::vector<Keywords> keywordsDisplay;
        std::vector<Keywords> keywordsAll;
        std::string approval;
        std::string canonical;
        std::string dataURI;
        GameNotes primaryKeyword;
        MlbMedia media;

      public:
        const AwayType &getType() const { return type; }
        AwayType &getMutableType() { return type; }
        void setType(const AwayType &value) { this->type = value; }

        const State &getState() const { return state; }
        State &getMutableState() { return state; }
        void setState(const State &value) { this->state = value; }

        const std::string &getDate() const { return date; }
        std::string &getMutableDate() { return date; }
        void setDate(const std::string &value) { this->date = value; }

        const std::string &getID() const { return id; }
        std::string &getMutableID() { return id; }
        void setID(const std::string &value) { this->id = value; }

        const std::string &getHeadline() const { return headline; }
        std::string &getMutableHeadline() { return headline; }
        void setHeadline(const std::string &value) { this->headline = value; }

        const std::string &getSubhead() const { return subhead; }
        std::string &getMutableSubhead() { return subhead; }
        void setSubhead(const std::string &value) { this->subhead = value; }

        const std::string &getSEOTitle() const { return seoTitle; }
        std::string &getMutableSEOTitle() { return seoTitle; }
        void setSEOTitle(const std::string &value) { this->seoTitle = value; }

        const std::string &getSEOKeywords() const { return seoKeywords; }
        std::string &getMutableSEOKeywords() { return seoKeywords; }
        void setSEOKeywords(const std::string &value) {
            this->seoKeywords = value;
        }

        const std::string &getSEODescription() const { return seoDescription; }
        std::string &getMutableSEODescription() { return seoDescription; }
        void setSEODescription(const std::string &value) {
            this->seoDescription = value;
        }

        const std::string &getSlug() const { return slug; }
        std::string &getMutableSlug() { return slug; }
        void setSlug(const std::string &value) { this->slug = value; }

        const bool &getCommenting() const { return commenting; }
        bool &getMutableCommenting() { return commenting; }
        void setCommenting(const bool &value) { this->commenting = value; }

        const Photo &getPhoto() const { return photo; }
        Photo &getMutablePhoto() { return photo; }
        void setPhoto(const Photo &value) { this->photo = value; }

        const Image &getImage() const { return image; }
        Image &getMutableImage() { return image; }
        void setImage(const Image &value) { this->image = value; }

        const TokenData &getTokenData() const { return tokenData; }
        TokenData &getMutableTokenData() { return tokenData; }
        void setTokenData(const TokenData &value) { this->tokenData = value; }

        const std::string &getBlurb() const { return blurb; }
        std::string &getMutableBlurb() { return blurb; }
        void setBlurb(const std::string &value) { this->blurb = value; }

        const std::string &getBody() const { return body; }
        std::string &getMutableBody() { return body; }
        void setBody(const std::string &value) { this->body = value; }

        const AwayContributor &getContributor() const { return contributor; }
        AwayContributor &getMutableContributor() { return contributor; }
        void setContributor(const AwayContributor &value) {
            this->contributor = value;
        }

        const std::vector<Keywords> &getKeywordsDisplay() const {
            return keywordsDisplay;
        }
        std::vector<Keywords> &getMutableKeywordsDisplay() {
            return keywordsDisplay;
        }
        void setKeywordsDisplay(const std::vector<Keywords> &value) {
            this->keywordsDisplay = value;
        }

        const std::vector<Keywords> &getKeywordsAll() const {
            return keywordsAll;
        }
        std::vector<Keywords> &getMutableKeywordsAll() { return keywordsAll; }
        void setKeywordsAll(const std::vector<Keywords> &value) {
            this->keywordsAll = value;
        }

        const std::string &getApproval() const { return approval; }
        std::string &getMutableApproval() { return approval; }
        void setApproval(const std::string &value) { this->approval = value; }

        const std::string &getCanonical() const { return canonical; }
        std::string &getMutableCanonical() { return canonical; }
        void setCanonical(const std::string &value) { this->canonical = value; }

        const std::string &getDataURI() const { return dataURI; }
        std::string &getMutableDataURI() { return dataURI; }
        void setDataURI(const std::string &value) { this->dataURI = value; }

        const GameNotes &getPrimaryKeyword() const { return primaryKeyword; }
        GameNotes &getMutablePrimaryKeyword() { return primaryKeyword; }
        void setPrimaryKeyword(const GameNotes &value) {
            this->primaryKeyword = value;
        }

        const MlbMedia &getMedia() const { return media; }
        MlbMedia &getMutableMedia() { return media; }
        void setMedia(const MlbMedia &value) { this->media = value; }
    };

    class Recap {
      public:
        Recap() = default;
        virtual ~Recap() = default;

      private:
        RecapAway home;
        RecapAway away;
        Mlb mlb;

      public:
        const RecapAway &getHome() const { return home; }
        RecapAway &getMutableHome() { return home; }
        void setHome(const RecapAway &value) { this->home = value; }

        const RecapAway &getAway() const { return away; }
        RecapAway &getMutableAway() { return away; }
        void setAway(const RecapAway &value) { this->away = value; }

        const Mlb &getMlb() const { return mlb; }
        Mlb &getMutableMlb() { return mlb; }
        void setMlb(const Mlb &value) { this->mlb = value; }
    };

    class Editorial {
      public:
        Editorial() = default;
        virtual ~Editorial() = default;

      private:
        Recap recap;

      public:
        const Recap &getRecap() const { return recap; }
        Recap &getMutableRecap() { return recap; }
        void setRecap(const Recap &value) { this->recap = value; }
    };

    class ContentMedia {
      public:
        ContentMedia() = default;
        virtual ~ContentMedia() = default;

      private:
        bool freeGame;
        bool enhancedGame;

      public:
        const bool &getFreeGame() const { return freeGame; }
        bool &getMutableFreeGame() { return freeGame; }
        void setFreeGame(const bool &value) { this->freeGame = value; }

        const bool &getEnhancedGame() const { return enhancedGame; }
        bool &getMutableEnhancedGame() { return enhancedGame; }
        void setEnhancedGame(const bool &value) { this->enhancedGame = value; }
    };

    class Content {
      public:
        Content() = default;
        virtual ~Content() = default;

      private:
        std::string link;
        Editorial editorial;
        ContentMedia media;
        GameNotes highlights;
        GameNotes summary;
        GameNotes gameNotes;

      public:
        const std::string &getLink() const { return link; }
        std::string &getMutableLink() { return link; }
        void setLink(const std::string &value) { this->link = value; }

        const Editorial &getEditorial() const { return editorial; }
        Editorial &getMutableEditorial() { return editorial; }
        void setEditorial(const Editorial &value) { this->editorial = value; }

        const ContentMedia &getMedia() const { return media; }
        ContentMedia &getMutableMedia() { return media; }
        void setMedia(const ContentMedia &value) { this->media = value; }

        const GameNotes &getHighlights() const { return highlights; }
        GameNotes &getMutableHighlights() { return highlights; }
        void setHighlights(const GameNotes &value) { this->highlights = value; }

        const GameNotes &getSummary() const { return summary; }
        GameNotes &getMutableSummary() { return summary; }
        void setSummary(const GameNotes &value) { this->summary = value; }

        const GameNotes &getGameNotes() const { return gameNotes; }
        GameNotes &getMutableGameNotes() { return gameNotes; }
        void setGameNotes(const GameNotes &value) { this->gameNotes = value; }
    };

    enum class DayNight : int { DAY, NIGHT };

    class Loser {
      public:
        Loser() = default;
        virtual ~Loser() = default;

      private:
        int64_t id;
        std::string fullName;
        std::string link;

      public:
        const int64_t &getID() const { return id; }
        int64_t &getMutableID() { return id; }
        void setID(const int64_t &value) { this->id = value; }

        const std::string &getFullName() const { return fullName; }
        std::string &getMutableFullName() { return fullName; }
        void setFullName(const std::string &value) { this->fullName = value; }

        const std::string &getLink() const { return link; }
        std::string &getMutableLink() { return link; }
        void setLink(const std::string &value) { this->link = value; }
    };

    class Decisions {
      public:
        Decisions() = default;
        virtual ~Decisions() = default;

      private:
        Loser winner;
        Loser loser;
        std::shared_ptr<Loser> save;

      public:
        const Loser &getWinner() const { return winner; }
        Loser &getMutableWinner() { return winner; }
        void setWinner(const Loser &value) { this->winner = value; }

        const Loser &getLoser() const { return loser; }
        Loser &getMutableLoser() { return loser; }
        void setLoser(const Loser &value) { this->loser = value; }

        std::shared_ptr<Loser> getSave() const { return save; }
        void setSave(std::shared_ptr<Loser> value) { this->save = value; }
    };

    enum class DoubleHeader : int { N };

    enum class GameType : int { R };

    enum class GamedayType : int { P };

    enum class IfNecessaryDescription : int { NORMAL_GAME };

    enum class RecordSource : int { S };

    enum class SeriesDescription : int { REGULAR_SEASON };

    enum class AbstractGameCode : int { F };

    enum class AbstractGameStateEnum : int { FINAL };

    class Status {
      public:
        Status() = default;
        virtual ~Status() = default;

      private:
        AbstractGameStateEnum abstractGameState;
        AbstractGameCode codedGameState;
        AbstractGameStateEnum detailedState;
        AbstractGameCode statusCode;
        AbstractGameCode abstractGameCode;

      public:
        const AbstractGameStateEnum &getAbstractGameState() const {
            return abstractGameState;
        }
        AbstractGameStateEnum &getMutableAbstractGameState() {
            return abstractGameState;
        }
        void setAbstractGameState(const AbstractGameStateEnum &value) {
            this->abstractGameState = value;
        }

        const AbstractGameCode &getCodedGameState() const {
            return codedGameState;
        }
        AbstractGameCode &getMutableCodedGameState() { return codedGameState; }
        void setCodedGameState(const AbstractGameCode &value) {
            this->codedGameState = value;
        }

        const AbstractGameStateEnum &getDetailedState() const {
            return detailedState;
        }
        AbstractGameStateEnum &getMutableDetailedState() {
            return detailedState;
        }
        void setDetailedState(const AbstractGameStateEnum &value) {
            this->detailedState = value;
        }

        const AbstractGameCode &getStatusCode() const { return statusCode; }
        AbstractGameCode &getMutableStatusCode() { return statusCode; }
        void setStatusCode(const AbstractGameCode &value) {
            this->statusCode = value;
        }

        const AbstractGameCode &getAbstractGameCode() const {
            return abstractGameCode;
        }
        AbstractGameCode &getMutableAbstractGameCode() {
            return abstractGameCode;
        }
        void setAbstractGameCode(const AbstractGameCode &value) {
            this->abstractGameCode = value;
        }
    };

    class LeagueRecord {
      public:
        LeagueRecord() = default;
        virtual ~LeagueRecord() = default;

      private:
        int64_t wins;
        int64_t losses;
        std::string pct;

      public:
        const int64_t &getWINS() const { return wins; }
        int64_t &getMutableWINS() { return wins; }
        void setWINS(const int64_t &value) { this->wins = value; }

        const int64_t &getLosses() const { return losses; }
        int64_t &getMutableLosses() { return losses; }
        void setLosses(const int64_t &value) { this->losses = value; }

        const std::string &getPct() const { return pct; }
        std::string &getMutablePct() { return pct; }
        void setPct(const std::string &value) { this->pct = value; }
    };

    class Venue {
      public:
        Venue() = default;
        virtual ~Venue() = default;

      private:
        int64_t id;
        std::string name;
        std::string link;

      public:
        const int64_t &getID() const { return id; }
        int64_t &getMutableID() { return id; }
        void setID(const int64_t &value) { this->id = value; }

        const std::string &getName() const { return name; }
        std::string &getMutableName() { return name; }
        void setName(const std::string &value) { this->name = value; }

        const std::string &getLink() const { return link; }
        std::string &getMutableLink() { return link; }
        void setLink(const std::string &value) { this->link = value; }
    };

    class TeamsAway {
      public:
        TeamsAway() = default;
        virtual ~TeamsAway() = default;

      private:
        LeagueRecord leagueRecord;
        int64_t score;
        Venue team;
        bool isWinner;
        bool splitSquad;
        int64_t seriesNumber;

      public:
        const LeagueRecord &getLeagueRecord() const { return leagueRecord; }
        LeagueRecord &getMutableLeagueRecord() { return leagueRecord; }
        void setLeagueRecord(const LeagueRecord &value) {
            this->leagueRecord = value;
        }

        const int64_t &getScore() const { return score; }
        int64_t &getMutableScore() { return score; }
        void setScore(const int64_t &value) { this->score = value; }

        const Venue &getTeam() const { return team; }
        Venue &getMutableTeam() { return team; }
        void setTeam(const Venue &value) { this->team = value; }

        const bool &getIsWinner() const { return isWinner; }
        bool &getMutableIsWinner() { return isWinner; }
        void setIsWinner(const bool &value) { this->isWinner = value; }

        const bool &getSplitSquad() const { return splitSquad; }
        bool &getMutableSplitSquad() { return splitSquad; }
        void setSplitSquad(const bool &value) { this->splitSquad = value; }

        const int64_t &getSeriesNumber() const { return seriesNumber; }
        int64_t &getMutableSeriesNumber() { return seriesNumber; }
        void setSeriesNumber(const int64_t &value) {
            this->seriesNumber = value;
        }
    };

    class Teams {
      public:
        Teams() = default;
        virtual ~Teams() = default;

      private:
        TeamsAway away;
        TeamsAway home;

      public:
        const TeamsAway &getAway() const { return away; }
        TeamsAway &getMutableAway() { return away; }
        void setAway(const TeamsAway &value) { this->away = value; }

        const TeamsAway &getHome() const { return home; }
        TeamsAway &getMutableHome() { return home; }
        void setHome(const TeamsAway &value) { this->home = value; }
    };

    class Game {
      public:
        Game() = default;
        virtual ~Game() = default;

      private:
        int64_t gamePk;
        std::string link;
        GameType gameType;
        std::string season;
        std::string gameDate;
        Status status;
        Teams teams;
        Decisions decisions;
        Venue venue;
        Content content;
        bool isTie;
        int64_t gameNumber;
        bool publicFacing;
        DoubleHeader doubleHeader;
        GamedayType gamedayType;
        DoubleHeader tiebreaker;
        std::string calendarEventID;
        std::string seasonDisplay;
        DayNight dayNight;
        int64_t scheduledInnings;
        int64_t inningBreakLength;
        int64_t gamesInSeries;
        int64_t seriesGameNumber;
        SeriesDescription seriesDescription;
        RecordSource recordSource;
        DoubleHeader ifNecessary;
        IfNecessaryDescription ifNecessaryDescription;

      public:
        const int64_t &getGamePk() const { return gamePk; }
        int64_t &getMutableGamePk() { return gamePk; }
        void setGamePk(const int64_t &value) { this->gamePk = value; }

        const std::string &getLink() const { return link; }
        std::string &getMutableLink() { return link; }
        void setLink(const std::string &value) { this->link = value; }

        const GameType &getGameType() const { return gameType; }
        GameType &getMutableGameType() { return gameType; }
        void setGameType(const GameType &value) { this->gameType = value; }

        const std::string &getSeason() const { return season; }
        std::string &getMutableSeason() { return season; }
        void setSeason(const std::string &value) { this->season = value; }

        const std::string &getGameDate() const { return gameDate; }
        std::string &getMutableGameDate() { return gameDate; }
        void setGameDate(const std::string &value) { this->gameDate = value; }

        const Status &getStatus() const { return status; }
        Status &getMutableStatus() { return status; }
        void setStatus(const Status &value) { this->status = value; }

        const Teams &getTeams() const { return teams; }
        Teams &getMutableTeams() { return teams; }
        void setTeams(const Teams &value) { this->teams = value; }

        const Decisions &getDecisions() const { return decisions; }
        Decisions &getMutableDecisions() { return decisions; }
        void setDecisions(const Decisions &value) { this->decisions = value; }

        const Venue &getVenue() const { return venue; }
        Venue &getMutableVenue() { return venue; }
        void setVenue(const Venue &value) { this->venue = value; }

        const Content &getContent() const { return content; }
        Content &getMutableContent() { return content; }
        void setContent(const Content &value) { this->content = value; }

        const bool &getIsTie() const { return isTie; }
        bool &getMutableIsTie() { return isTie; }
        void setIsTie(const bool &value) { this->isTie = value; }

        const int64_t &getGameNumber() const { return gameNumber; }
        int64_t &getMutableGameNumber() { return gameNumber; }
        void setGameNumber(const int64_t &value) { this->gameNumber = value; }

        const bool &getPublicFacing() const { return publicFacing; }
        bool &getMutablePublicFacing() { return publicFacing; }
        void setPublicFacing(const bool &value) { this->publicFacing = value; }

        const DoubleHeader &getDoubleHeader() const { return doubleHeader; }
        DoubleHeader &getMutableDoubleHeader() { return doubleHeader; }
        void setDoubleHeader(const DoubleHeader &value) {
            this->doubleHeader = value;
        }

        const GamedayType &getGamedayType() const { return gamedayType; }
        GamedayType &getMutableGamedayType() { return gamedayType; }
        void setGamedayType(const GamedayType &value) {
            this->gamedayType = value;
        }

        const DoubleHeader &getTiebreaker() const { return tiebreaker; }
        DoubleHeader &getMutableTiebreaker() { return tiebreaker; }
        void setTiebreaker(const DoubleHeader &value) {
            this->tiebreaker = value;
        }

        const std::string &getCalendarEventID() const {
            return calendarEventID;
        }
        std::string &getMutableCalendarEventID() { return calendarEventID; }
        void setCalendarEventID(const std::string &value) {
            this->calendarEventID = value;
        }

        const std::string &getSeasonDisplay() const { return seasonDisplay; }
        std::string &getMutableSeasonDisplay() { return seasonDisplay; }
        void setSeasonDisplay(const std::string &value) {
            this->seasonDisplay = value;
        }

        const DayNight &getDayNight() const { return dayNight; }
        DayNight &getMutableDayNight() { return dayNight; }
        void setDayNight(const DayNight &value) { this->dayNight = value; }

        const int64_t &getScheduledInnings() const { return scheduledInnings; }
        int64_t &getMutableScheduledInnings() { return scheduledInnings; }
        void setScheduledInnings(const int64_t &value) {
            this->scheduledInnings = value;
        }

        const int64_t &getInningBreakLength() const {
            return inningBreakLength;
        }
        int64_t &getMutableInningBreakLength() { return inningBreakLength; }
        void setInningBreakLength(const int64_t &value) {
            this->inningBreakLength = value;
        }

        const int64_t &getGamesInSeries() const { return gamesInSeries; }
        int64_t &getMutableGamesInSeries() { return gamesInSeries; }
        void setGamesInSeries(const int64_t &value) {
            this->gamesInSeries = value;
        }

        const int64_t &getSeriesGameNumber() const { return seriesGameNumber; }
        int64_t &getMutableSeriesGameNumber() { return seriesGameNumber; }
        void setSeriesGameNumber(const int64_t &value) {
            this->seriesGameNumber = value;
        }

        const SeriesDescription &getSeriesDescription() const {
            return seriesDescription;
        }
        SeriesDescription &getMutableSeriesDescription() {
            return seriesDescription;
        }
        void setSeriesDescription(const SeriesDescription &value) {
            this->seriesDescription = value;
        }

        const RecordSource &getRecordSource() const { return recordSource; }
        RecordSource &getMutableRecordSource() { return recordSource; }
        void setRecordSource(const RecordSource &value) {
            this->recordSource = value;
        }

        const DoubleHeader &getIfNecessary() const { return ifNecessary; }
        DoubleHeader &getMutableIfNecessary() { return ifNecessary; }
        void setIfNecessary(const DoubleHeader &value) {
            this->ifNecessary = value;
        }

        const IfNecessaryDescription &getIfNecessaryDescription() const {
            return ifNecessaryDescription;
        }
        IfNecessaryDescription &getMutableIfNecessaryDescription() {
            return ifNecessaryDescription;
        }
        void setIfNecessaryDescription(const IfNecessaryDescription &value) {
            this->ifNecessaryDescription = value;
        }
    };

    class DateElement {
      public:
        DateElement() = default;
        virtual ~DateElement() = default;

      private:
        std::string date;
        int64_t totalItems;
        int64_t totalEvents;
        int64_t totalGames;
        int64_t totalGamesInProgress;
        std::vector<Game> games;
        std::vector<nlohmann::json> events;

      public:
        const std::string &getDate() const { return date; }
        std::string &getMutableDate() { return date; }
        void setDate(const std::string &value) { this->date = value; }

        const int64_t &getTotalItems() const { return totalItems; }
        int64_t &getMutableTotalItems() { return totalItems; }
        void setTotalItems(const int64_t &value) { this->totalItems = value; }

        const int64_t &getTotalEvents() const { return totalEvents; }
        int64_t &getMutableTotalEvents() { return totalEvents; }
        void setTotalEvents(const int64_t &value) { this->totalEvents = value; }

        const int64_t &getTotalGames() const { return totalGames; }
        int64_t &getMutableTotalGames() { return totalGames; }
        void setTotalGames(const int64_t &value) { this->totalGames = value; }

        const int64_t &getTotalGamesInProgress() const {
            return totalGamesInProgress;
        }
        int64_t &getMutableTotalGamesInProgress() {
            return totalGamesInProgress;
        }
        void setTotalGamesInProgress(const int64_t &value) {
            this->totalGamesInProgress = value;
        }

        const std::vector<Game> &getGames() const { return games; }
        std::vector<Game> &getMutableGames() { return games; }
        void setGames(const std::vector<Game> &value) { this->games = value; }

        const std::vector<nlohmann::json> &getEvents() const { return events; }
        std::vector<nlohmann::json> &getMutableEvents() { return events; }
        void setEvents(const std::vector<nlohmann::json> &value) {
            this->events = value;
        }
    };

    class Dss {
      public:
        Dss() = default;
        virtual ~Dss() = default;

      private:
        std::string copyright;
        int64_t totalItems;
        int64_t totalEvents;
        int64_t totalGames;
        int64_t totalGamesInProgress;
        std::vector<DateElement> dates;

      public:
        const std::string &getCopyright() const { return copyright; }
        std::string &getMutableCopyright() { return copyright; }
        void setCopyright(const std::string &value) { this->copyright = value; }

        const int64_t &getTotalItems() const { return totalItems; }
        int64_t &getMutableTotalItems() { return totalItems; }
        void setTotalItems(const int64_t &value) { this->totalItems = value; }

        const int64_t &getTotalEvents() const { return totalEvents; }
        int64_t &getMutableTotalEvents() { return totalEvents; }
        void setTotalEvents(const int64_t &value) { this->totalEvents = value; }

        const int64_t &getTotalGames() const { return totalGames; }
        int64_t &getMutableTotalGames() { return totalGames; }
        void setTotalGames(const int64_t &value) { this->totalGames = value; }

        const int64_t &getTotalGamesInProgress() const {
            return totalGamesInProgress;
        }
        int64_t &getMutableTotalGamesInProgress() {
            return totalGamesInProgress;
        }
        void setTotalGamesInProgress(const int64_t &value) {
            this->totalGamesInProgress = value;
        }

        const std::vector<DateElement> &getDates() const { return dates; }
        std::vector<DateElement> &getMutableDates() { return dates; }
        void setDates(const std::vector<DateElement> &value) {
            this->dates = value;
        }
    };
} // namespace MLBJson

namespace nlohmann {
    void from_json(const json &j, MLBJson::ContributorElement &x);
    void to_json(json &j, const MLBJson::ContributorElement &x);

    void from_json(const json &j, MLBJson::AwayContributor &x);
    void to_json(json &j, const MLBJson::AwayContributor &x);

    void from_json(const json &j, MLBJson::Cut &x);
    void to_json(json &j, const MLBJson::Cut &x);

    void from_json(const json &j, MLBJson::Image &x);
    void to_json(json &j, const MLBJson::Image &x);

    void from_json(const json &j, MLBJson::Keywords &x);
    void to_json(json &j, const MLBJson::Keywords &x);

    void from_json(const json &j, MLBJson::GameNotes &x);
    void to_json(json &j, const MLBJson::GameNotes &x);

    void from_json(const json &j, MLBJson::Photo &x);
    void to_json(json &j, const MLBJson::Photo &x);

    void from_json(const json &j, MLBJson::ArakGroundhog &x);
    void to_json(json &j, const MLBJson::ArakGroundhog &x);

    void from_json(const json &j, MLBJson::MediaUrls &x);
    void to_json(json &j, const MLBJson::MediaUrls &x);

    void from_json(const json &j, MLBJson::Tag &x);
    void to_json(json &j, const MLBJson::Tag &x);

    void from_json(const json &j, MLBJson::ChiangMaiGoose &x);
    void to_json(json &j, const MLBJson::ChiangMaiGoose &x);

    void from_json(const json &j, MLBJson::Token &x);
    void to_json(json &j, const MLBJson::Token &x);

    void from_json(const json &j, MLBJson::Token31Dc1509Db328F11Ce0Ac &x);
    void to_json(json &j, const MLBJson::Token31Dc1509Db328F11Ce0Ac &x);

    void from_json(const json &j, MLBJson::TokenData &x);
    void to_json(json &j, const MLBJson::TokenData &x);

    void from_json(const json &j, MLBJson::RecapAway &x);
    void to_json(json &j, const MLBJson::RecapAway &x);

    void from_json(const json &j, MLBJson::Playback &x);
    void to_json(json &j, const MLBJson::Playback &x);

    void from_json(const json &j, MLBJson::MlbMedia &x);
    void to_json(json &j, const MLBJson::MlbMedia &x);

    void from_json(const json &j, MLBJson::Mlb &x);
    void to_json(json &j, const MLBJson::Mlb &x);

    void from_json(const json &j, MLBJson::Recap &x);
    void to_json(json &j, const MLBJson::Recap &x);

    void from_json(const json &j, MLBJson::Editorial &x);
    void to_json(json &j, const MLBJson::Editorial &x);

    void from_json(const json &j, MLBJson::ContentMedia &x);
    void to_json(json &j, const MLBJson::ContentMedia &x);

    void from_json(const json &j, MLBJson::Content &x);
    void to_json(json &j, const MLBJson::Content &x);

    void from_json(const json &j, MLBJson::Loser &x);
    void to_json(json &j, const MLBJson::Loser &x);

    void from_json(const json &j, MLBJson::Decisions &x);
    void to_json(json &j, const MLBJson::Decisions &x);

    void from_json(const json &j, MLBJson::Status &x);
    void to_json(json &j, const MLBJson::Status &x);

    void from_json(const json &j, MLBJson::LeagueRecord &x);
    void to_json(json &j, const MLBJson::LeagueRecord &x);

    void from_json(const json &j, MLBJson::Venue &x);
    void to_json(json &j, const MLBJson::Venue &x);

    void from_json(const json &j, MLBJson::TeamsAway &x);
    void to_json(json &j, const MLBJson::TeamsAway &x);

    void from_json(const json &j, MLBJson::Teams &x);
    void to_json(json &j, const MLBJson::Teams &x);

    void from_json(const json &j, MLBJson::Game &x);
    void to_json(json &j, const MLBJson::Game &x);

    void from_json(const json &j, MLBJson::DateElement &x);
    void to_json(json &j, const MLBJson::DateElement &x);

    void from_json(const json &j, MLBJson::Dss &x);
    void to_json(json &j, const MLBJson::Dss &x);

    void from_json(const json &j, MLBJson::Source &x);
    void to_json(json &j, const MLBJson::Source &x);

    void from_json(const json &j, MLBJson::AspectRatio &x);
    void to_json(json &j, const MLBJson::AspectRatio &x);

    void from_json(const json &j, MLBJson::TypeEnum &x);
    void to_json(json &j, const MLBJson::TypeEnum &x);

    void from_json(const json &j, MLBJson::State &x);
    void to_json(json &j, const MLBJson::State &x);

    void from_json(const json &j, MLBJson::PurpleType &x);
    void to_json(json &j, const MLBJson::PurpleType &x);

    void from_json(const json &j, MLBJson::DateEnum &x);
    void to_json(json &j, const MLBJson::DateEnum &x);

    void from_json(const json &j, MLBJson::FluffyType &x);
    void to_json(json &j, const MLBJson::FluffyType &x);

    void from_json(const json &j, MLBJson::TentacledType &x);
    void to_json(json &j, const MLBJson::TentacledType &x);

    void from_json(const json &j, MLBJson::AwayType &x);
    void to_json(json &j, const MLBJson::AwayType &x);

    void from_json(const json &j, MLBJson::Language &x);
    void to_json(json &j, const MLBJson::Language &x);

    void from_json(const json &j, MLBJson::MediaState &x);
    void to_json(json &j, const MLBJson::MediaState &x);

    void from_json(const json &j, MLBJson::Name &x);
    void to_json(json &j, const MLBJson::Name &x);

    void from_json(const json &j, MLBJson::DayNight &x);
    void to_json(json &j, const MLBJson::DayNight &x);

    void from_json(const json &j, MLBJson::DoubleHeader &x);
    void to_json(json &j, const MLBJson::DoubleHeader &x);

    void from_json(const json &j, MLBJson::GameType &x);
    void to_json(json &j, const MLBJson::GameType &x);

    void from_json(const json &j, MLBJson::GamedayType &x);
    void to_json(json &j, const MLBJson::GamedayType &x);

    void from_json(const json &j, MLBJson::IfNecessaryDescription &x);
    void to_json(json &j, const MLBJson::IfNecessaryDescription &x);

    void from_json(const json &j, MLBJson::RecordSource &x);
    void to_json(json &j, const MLBJson::RecordSource &x);

    void from_json(const json &j, MLBJson::SeriesDescription &x);
    void to_json(json &j, const MLBJson::SeriesDescription &x);

    void from_json(const json &j, MLBJson::AbstractGameCode &x);
    void to_json(json &j, const MLBJson::AbstractGameCode &x);

    void from_json(const json &j, MLBJson::AbstractGameStateEnum &x);
    void to_json(json &j, const MLBJson::AbstractGameStateEnum &x);

    inline void from_json(const json &j, MLBJson::ContributorElement &x) {
        x.setName(j.at("name").get<std::string>());
        x.setSource(j.at("source").get<MLBJson::Source>());
        x.setTagline(j.at("tagline").get<std::string>());
        x.setTwitter(j.at("twitter").get<std::string>());
    }

    inline void to_json(json &j, const MLBJson::ContributorElement &x) {
        j = json::object();
        j["name"] = x.getName();
        j["source"] = x.getSource();
        j["tagline"] = x.getTagline();
        j["twitter"] = x.getTwitter();
    }

    inline void from_json(const json &j, MLBJson::AwayContributor &x) {
        x.setContributors(j.at("contributors")
                              .get<std::vector<MLBJson::ContributorElement>>());
        x.setSource(j.at("source").get<MLBJson::Source>());
        x.setImage(j.at("image").get<std::string>());
    }

    inline void to_json(json &j, const MLBJson::AwayContributor &x) {
        j = json::object();
        j["contributors"] = x.getContributors();
        j["source"] = x.getSource();
        j["image"] = x.getImage();
    }

    inline void from_json(const json &j, MLBJson::Cut &x) {
        x.setAspectRatio(j.at("aspectRatio").get<MLBJson::AspectRatio>());
        x.setWidth(j.at("width").get<int64_t>());
        x.setHeight(j.at("height").get<int64_t>());
        x.setSrc(j.at("src").get<std::string>());
        x.setAt2X(j.at("at2x").get<std::string>());
        x.setAt3X(j.at("at3x").get<std::string>());
    }

    inline void to_json(json &j, const MLBJson::Cut &x) {
        j = json::object();
        j["aspectRatio"] = x.getAspectRatio();
        j["width"] = x.getWidth();
        j["height"] = x.getHeight();
        j["src"] = x.getSrc();
        j["at2x"] = x.getAt2X();
        j["at3x"] = x.getAt3X();
    }

    inline void from_json(const json &j, MLBJson::Image &x) {
        x.setTitle(j.at("title").get<std::string>());
        x.setAltText(j.at("altText").get<std::string>());
        x.setCuts(j.at("cuts").get<std::vector<MLBJson::Cut>>());
    }

    inline void to_json(json &j, const MLBJson::Image &x) {
        j = json::object();
        j["title"] = x.getTitle();
        j["altText"] = x.getAltText();
        j["cuts"] = x.getCuts();
    }

    inline void from_json(const json &j, MLBJson::Keywords &x) {
        x.setType(j.at("type").get<MLBJson::TypeEnum>());
        x.setValue(j.at("value").get<std::string>());
        x.setDisplayName(j.at("displayName").get<std::string>());
    }

    inline void to_json(json &j, const MLBJson::Keywords &x) {
        j = json::object();
        j["type"] = x.getType();
        j["value"] = x.getValue();
        j["displayName"] = x.getDisplayName();
    }

    inline void from_json(const json &j, MLBJson::GameNotes &x) {}

    inline void to_json(json &j, const MLBJson::GameNotes &x) {
        j = json::object();
    }

    inline void from_json(const json &j, MLBJson::Photo &x) {
        x.setTitle(j.at("title").get<std::string>());
        x.setAltText(j.at("altText").get<std::string>());
        x.setCuts(j.at("cuts").get<std::map<std::string, MLBJson::Cut>>());
    }

    inline void to_json(json &j, const MLBJson::Photo &x) {
        j = json::object();
        j["title"] = x.getTitle();
        j["altText"] = x.getAltText();
        j["cuts"] = x.getCuts();
    }

    inline void from_json(const json &j, MLBJson::ArakGroundhog &x) {
        x.setTokenGUID(j.at("tokenGUID").get<std::string>());
        x.setType(j.at("type").get<MLBJson::PurpleType>());
        x.setID(j.at("id").get<std::string>());
        x.setPosition(j.at("position").get<std::string>());
        x.setName(j.at("name").get<std::string>());
        x.setSEOName(j.at("seoName").get<std::string>());
    }

    inline void to_json(json &j, const MLBJson::ArakGroundhog &x) {
        j = json::object();
        j["tokenGUID"] = x.getTokenGUID();
        j["type"] = x.getType();
        j["id"] = x.getID();
        j["position"] = x.getPosition();
        j["name"] = x.getName();
        j["seoName"] = x.getSEOName();
    }

    inline void from_json(const json &j, MLBJson::MediaUrls &x) {
        x.setFlash450K400X224(j.at("FLASH_450K_400X224").get<std::string>());
        x.setFlash1200K640X360(j.at("FLASH_1200K_640X360").get<std::string>());
        x.setFlash1800K960X540(j.at("FLASH_1800K_960X540").get<std::string>());
        x.setFlash2500K1280X720(
            j.at("FLASH_2500K_1280X720").get<std::string>());
        x.setHTTPCloudMobile(j.at("HTTP_CLOUD_MOBILE").get<std::string>());
        x.setHTTPCloudTablet(j.at("HTTP_CLOUD_TABLET").get<std::string>());
        x.setHTTPCloudTablet60(j.at("HTTP_CLOUD_TABLET_60").get<std::string>());
        x.setHTTPCloudAndroidTablet(
            j.at("HTTP_CLOUD_ANDROID_TABLET").get<std::string>());
        x.setHTTPCloudWired(j.at("HTTP_CLOUD_WIRED").get<std::string>());
        x.setHTTPCloudWired60(j.at("HTTP_CLOUD_WIRED_60").get<std::string>());
        x.setHTTPCloudWiredWeb(j.at("HTTP_CLOUD_WIRED_WEB").get<std::string>());
    }

    inline void to_json(json &j, const MLBJson::MediaUrls &x) {
        j = json::object();
        j["FLASH_450K_400X224"] = x.getFlash450K400X224();
        j["FLASH_1200K_640X360"] = x.getFlash1200K640X360();
        j["FLASH_1800K_960X540"] = x.getFlash1800K960X540();
        j["FLASH_2500K_1280X720"] = x.getFlash2500K1280X720();
        j["HTTP_CLOUD_MOBILE"] = x.getHTTPCloudMobile();
        j["HTTP_CLOUD_TABLET"] = x.getHTTPCloudTablet();
        j["HTTP_CLOUD_TABLET_60"] = x.getHTTPCloudTablet60();
        j["HTTP_CLOUD_ANDROID_TABLET"] = x.getHTTPCloudAndroidTablet();
        j["HTTP_CLOUD_WIRED"] = x.getHTTPCloudWired();
        j["HTTP_CLOUD_WIRED_60"] = x.getHTTPCloudWired60();
        j["HTTP_CLOUD_WIRED_WEB"] = x.getHTTPCloudWiredWeb();
    }

    inline void from_json(const json &j, MLBJson::Tag &x) {
        x.setType(j.at("@type").get<MLBJson::TypeEnum>());
        x.setValue(j.at("@value").get<std::string>());
        x.setDisplayName(MLBJson::get_optional<std::string>(j, "@displayName"));
    }

    inline void to_json(json &j, const MLBJson::Tag &x) {
        j = json::object();
        j["@type"] = x.getType();
        j["@value"] = x.getValue();
        j["@displayName"] = x.getDisplayName();
    }

    inline void from_json(const json &j, MLBJson::ChiangMaiGoose &x) {
        x.setTokenGUID(j.at("tokenGUID").get<std::string>());
        x.setType(j.at("type").get<MLBJson::FluffyType>());
        x.setVideoID(j.at("videoId").get<std::string>());
        x.setHref(j.at("href").get<std::string>());
        x.setTags(j.at("tags").get<std::vector<MLBJson::Tag>>());
        x.setDate(j.at("date").get<MLBJson::DateEnum>());
        x.setHeadline(j.at("headline").get<std::string>());
        x.setDuration(j.at("duration").get<std::string>());
        x.setBlurb(j.at("blurb").get<std::string>());
        x.setBigBlurb(MLBJson::get_optional<std::string>(j, "bigBlurb"));
        x.setPreviewImage(j.at("previewImage").get<std::string>());
        x.setPlaybackURLMobile(j.at("playbackUrlMobile").get<std::string>());
        x.setPlaybackURLTablet(j.at("playbackUrlTablet").get<std::string>());
        x.setMediaURLS(j.at("mediaURLS").get<MLBJson::MediaUrls>());
        x.setShareable(MLBJson::get_optional<bool>(j, "shareable"));
    }

    inline void to_json(json &j, const MLBJson::ChiangMaiGoose &x) {
        j = json::object();
        j["tokenGUID"] = x.getTokenGUID();
        j["type"] = x.getType();
        j["videoId"] = x.getVideoID();
        j["href"] = x.getHref();
        j["tags"] = x.getTags();
        j["date"] = x.getDate();
        j["headline"] = x.getHeadline();
        j["duration"] = x.getDuration();
        j["blurb"] = x.getBlurb();
        j["bigBlurb"] = x.getBigBlurb();
        j["previewImage"] = x.getPreviewImage();
        j["playbackUrlMobile"] = x.getPlaybackURLMobile();
        j["playbackUrlTablet"] = x.getPlaybackURLTablet();
        j["mediaURLS"] = x.getMediaURLS();
        j["shareable"] = x.getShareable();
    }

    inline void from_json(const json &j, MLBJson::Token &x) {
        x.setTokenGUID(j.at("tokenGUID").get<std::string>());
        x.setType(j.at("type").get<MLBJson::TentacledType>());
        x.setHref(j.at("href").get<std::string>());
        x.setHrefMobile(j.at("hrefMobile").get<std::string>());
    }

    inline void to_json(json &j, const MLBJson::Token &x) {
        j = json::object();
        j["tokenGUID"] = x.getTokenGUID();
        j["type"] = x.getType();
        j["href"] = x.getHref();
        j["hrefMobile"] = x.getHrefMobile();
    }

    inline void from_json(const json &j,
                          MLBJson::Token31Dc1509Db328F11Ce0Ac &x) {
        x.setTokenGUID(j.at("tokenGUID").get<std::string>());
        x.setType(j.at("type").get<std::string>());
        x.setSubType(j.at("subType").get<std::string>());
        x.setEmbedID(j.at("embedId").get<std::string>());
        x.setAuthorName(j.at("authorName").get<std::string>());
        x.setAuthorURL(j.at("authorUrl").get<std::string>());
        x.setHeight(MLBJson::get_untyped(j, "height"));
        x.setWidth(j.at("width").get<int64_t>());
        x.setHTML(j.at("html").get<std::string>());
        x.setHref(j.at("href").get<std::string>());
    }

    inline void to_json(json &j, const MLBJson::Token31Dc1509Db328F11Ce0Ac &x) {
        j = json::object();
        j["tokenGUID"] = x.getTokenGUID();
        j["type"] = x.getType();
        j["subType"] = x.getSubType();
        j["embedId"] = x.getEmbedID();
        j["authorName"] = x.getAuthorName();
        j["authorUrl"] = x.getAuthorURL();
        j["height"] = x.getHeight();
        j["width"] = x.getWidth();
        j["html"] = x.getHTML();
        j["href"] = x.getHref();
    }

    inline void from_json(const json &j, MLBJson::TokenData &x) {
        x.setToken23730D7C7D9AA9F7C5E85(MLBJson::get_optional<MLBJson::Token>(
            j, "token-23730D7C7D9AA9F7C5E85"));
        x.setTokenC91ACC313F379CD2B52B8(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-C91ACC313F379CD2B52B8"));
        x.setTokenE6D877BB9EC2A8D9D039C(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-E6D877BB9EC2A8D9D039C"));
        x.setToken56D431904961877F1F5BE(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-56D431904961877F1F5BE"));
        x.setToken412467956BE5CDFFAF4B2(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-412467956BE5CDFFAF4B2"));
        x.setToken5DAE442BC99D96A8B96BF(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-5DAE442BC99D96A8B96BF"));
        x.setToken9FA7F2E5B8A9875EE0B94(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-9FA7F2E5B8A9875EE0B94"));
        x.setToken460084A221436934CEBBE(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-460084A221436934CEBBE"));
        x.setToken275E1DD943030C5B5FB9D(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-275E1DD943030C5B5FB9D"));
        x.setToken212DE831C266CB42802BC(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-212DE831C266CB42802BC"));
        x.setTokenE09A5C6B0D7BB2C4551B6(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E09A5C6B0D7BB2C4551B6"));
        x.setToken3055644DABCB711618A81(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-3055644DABCB711618A81"));
        x.setToken8D9DAA42490BC0B227599(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-8D9DAA42490BC0B227599"));
        x.setToken760E83788F63C48DDF7AD(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-760E83788F63C48DDF7AD"));
        x.setTokenACEB6A8D4FD80CC07ECA7(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-ACEB6A8D4FD80CC07ECA7"));
        x.setToken91AD363841ED76C7060A7(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-91AD363841ED76C7060A7"));
        x.setToken68CA80F95ED6B4A6A77A8(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-68CA80F95ED6B4A6A77A8"));
        x.setToken55F7368BE04958F4173A0(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-55F7368BE04958F4173A0"));
        x.setToken64CD4F91E838690A6C98F(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-64CD4F91E838690A6C98F"));
        x.setToken5F3A93356640B35066AB0(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-5F3A93356640B35066AB0"));
        x.setTokenF352FC9E205DF80BBB9A1(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-F352FC9E205DF80BBB9A1"));
        x.setTokenCC4A8F62FBB98029F49BA(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CC4A8F62FBB98029F49BA"));
        x.setToken9C784204BF18430ED5BB4(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9C784204BF18430ED5BB4"));
        x.setTokenF1B435C49B4E098FEC386(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-F1B435C49B4E098FEC386"));
        x.setToken549ED10CFB146448E9CBD(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-549ED10CFB146448E9CBD"));
        x.setTokenFC81372023C05244CC0BE(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-FC81372023C05244CC0BE"));
        x.setTokenA01CA209CC332D81E0489(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-A01CA209CC332D81E0489"));
        x.setTokenF7330F5A16C0560ED6CA4(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-F7330F5A16C0560ED6CA4"));
        x.setTokenE673EA12C41DA76D45188(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E673EA12C41DA76D45188"));
        x.setToken2836C14E0570C3E685693(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-2836C14E0570C3E685693"));
        x.setToken234DA65DCF4B07EE7FAB9(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-234DA65DCF4B07EE7FAB9"));
        x.setToken3AF0395C10670B84922A4(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-3AF0395C10670B84922A4"));
        x.setToken1991AA23E3C62AA661FAC(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-1991AA23E3C62AA661FAC"));
        x.setToken8E0C32852C68A118C76A7(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-8E0C32852C68A118C76A7"));
        x.setTokenC23474240906E85A9AF97(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-C23474240906E85A9AF97"));
        x.setToken66285580C871C449AA2AF(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-66285580C871C449AA2AF"));
        x.setToken8584EAFA2CD964D3F359D(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-8584EAFA2CD964D3F359D"));
        x.setToken6745E57514242D6D69782(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-6745E57514242D6D69782"));
        x.setToken38928BB57CE50F1C31FAD(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-38928BB57CE50F1C31FAD"));
        x.setToken9C0B2BEAA6DFD31524EAB(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9C0B2BEAA6DFD31524EAB"));
        x.setToken1CD29147D64EBEEBB8F9F(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-1CD29147D64EBEEBB8F9F"));
        x.setTokenF4B9964747E6117A18D9E(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-F4B9964747E6117A18D9E"));
        x.setToken9537EB58E6571B5018A88(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9537EB58E6571B5018A88"));
        x.setTokenE3D3B4D9DE79219AF61B5(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E3D3B4D9DE79219AF61B5"));
        x.setTokenE44A9E703B514FE9DCF8F(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E44A9E703B514FE9DCF8F"));
        x.setToken6A498B883DC78DF271CAB(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-6A498B883DC78DF271CAB"));
        x.setToken457F3E65BD903C1FC8AAE(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-457F3E65BD903C1FC8AAE"));
        x.setTokenB952619F7911BD23953BD(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-B952619F7911BD23953BD"));
        x.setToken5FB0AA57C2A4D9A752093(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-5FB0AA57C2A4D9A752093"));
        x.setToken403A70FFCF76D500D0492(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-403A70FFCF76D500D0492"));
        x.setToken2BF7F992E24CB42B8F497(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-2BF7F992E24CB42B8F497"));
        x.setTokenD11FB99FC582DA9D129A9(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-D11FB99FC582DA9D129A9"));
        x.setToken37F9A03CEE7D128E78F8E(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-37F9A03CEE7D128E78F8E"));
        x.setTokenF1AC4F490B957534BC2BA(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-F1AC4F490B957534BC2BA"));
        x.setTokenEE5431A399A2EA755F985(MLBJson::get_optional<MLBJson::Token>(
            j, "token-EE5431A399A2EA755F985"));
        x.setToken7C7D7205D6AF7E6A35AB6(MLBJson::get_optional<MLBJson::Token>(
            j, "token-7C7D7205D6AF7E6A35AB6"));
        x.setToken7FEFC21E98FBD0DE662BE(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-7FEFC21E98FBD0DE662BE"));
        x.setToken5F4FCB0691087ABE512A6(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-5F4FCB0691087ABE512A6"));
        x.setToken73B814D8560F9AB7FA181(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-73B814D8560F9AB7FA181"));
        x.setToken1BE5802AEE0CBAB99B882(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-1BE5802AEE0CBAB99B882"));
        x.setToken9F7A70A34D6F5C0FB3E88(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-9F7A70A34D6F5C0FB3E88"));
        x.setToken9BBD87FF0925CB6CBA2A6(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-9BBD87FF0925CB6CBA2A6"));
        x.setTokenE973C7D95C067E9422E89(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E973C7D95C067E9422E89"));
        x.setToken4A8B125DFC764AAB727A7(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-4A8B125DFC764AAB727A7"));
        x.setToken05E57D99C3CD69F05C7BC(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-05E57D99C3CD69F05C7BC"));
        x.setTokenF889173B1228AC1E84FA3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-F889173B1228AC1E84FA3"));
        x.setTokenDD46C0D463EB26DE473B5(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-DD46C0D463EB26DE473B5"));
        x.setTokenE76ABAC6694B03E9CE087(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E76ABAC6694B03E9CE087"));
        x.setTokenD28FD03E38ACE143DF1BA(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-D28FD03E38ACE143DF1BA"));
        x.setToken020A9754A3089AC08B48C(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-020A9754A3089AC08B48C"));
        x.setToken5F5D6D55FC1A1735A8C91(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-5F5D6D55FC1A1735A8C91"));
        x.setTokenCEA6AB430FA895B14D38C(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CEA6AB430FA895B14D38C"));
        x.setToken69F211937F19241D2719A(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-69F211937F19241D2719A"));
        x.setTokenB23C7403A039BD742F790(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-B23C7403A039BD742F790"));
        x.setToken7FFE1F12B5DE3C78BD5B3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-7FFE1F12B5DE3C78BD5B3"));
        x.setTokenC2FB3EC7DD3C5A14987A4(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-C2FB3EC7DD3C5A14987A4"));
        x.setToken189330D6BFCA399608FB4(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-189330D6BFCA399608FB4"));
        x.setTokenAF767EF443126B3CCD8AF(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-AF767EF443126B3CCD8AF"));
        x.setToken773BE241B74FA7597F780(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-773BE241B74FA7597F780"));
        x.setToken1BE823E3464AD53321FB1(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-1BE823E3464AD53321FB1"));
        x.setToken5F162503444CFEC22AF81(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-5F162503444CFEC22AF81"));
        x.setToken13ACDBA5AF1CC23DF99BA(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-13ACDBA5AF1CC23DF99BA"));
        x.setToken9FDF39287E87C1B324894(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9FDF39287E87C1B324894"));
        x.setTokenA32E4613028FD614C2992(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-A32E4613028FD614C2992"));
        x.setTokenA433BA409058D6BE952A5(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-A433BA409058D6BE952A5"));
        x.setToken7CF34D79E5F77AD7595B5(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-7CF34D79E5F77AD7595B5"));
        x.setToken92B8DA5E1E3E67C80D793(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-92B8DA5E1E3E67C80D793"));
        x.setToken75BD980A2FAC6679C9CA9(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-75BD980A2FAC6679C9CA9"));
        x.setToken804528C0EDB6908B0B899(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-804528C0EDB6908B0B899"));
        x.setTokenCBA976567E4283E3E9E9B(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CBA976567E4283E3E9E9B"));
        x.setToken99C6A24D2A561187A77BA(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-99C6A24D2A561187A77BA"));
        x.setToken25B4946A8DC84F7E5F0AA(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-25B4946A8DC84F7E5F0AA"));
        x.setTokenC75FA378013EC28E08CA9(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-C75FA378013EC28E08CA9"));
        x.setToken4B8879991B0C58A8DE786(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-4B8879991B0C58A8DE786"));
        x.setToken5DC7CA1D490AB35523D9E(MLBJson::get_optional<MLBJson::Token>(
            j, "token-5DC7CA1D490AB35523D9E"));
        x.setToken7D071A1FBCAE3D2EC0C90(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-7D071A1FBCAE3D2EC0C90"));
        x.setTokenD9214DB82A79855D1859D(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-D9214DB82A79855D1859D"));
        x.setToken410A7675F420C35808D87(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-410A7675F420C35808D87"));
        x.setTokenA9E0E34E0D049ABBC058C(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-A9E0E34E0D049ABBC058C"));
        x.setToken6606AC90A18517646E98C(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-6606AC90A18517646E98C"));
        x.setToken31DC1509DB328F11CE0AC(
            MLBJson::get_optional<MLBJson::Token31Dc1509Db328F11Ce0Ac>(
                j, "token-31DC1509DB328F11CE0AC"));
        x.setToken2257B2C2C7580FB792CA6(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-2257B2C2C7580FB792CA6"));
        x.setToken9DF69821A140BE2EE72A7(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9DF69821A140BE2EE72A7"));
        x.setToken73FE56D22D475C7AEDDBC(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-73FE56D22D475C7AEDDBC"));
        x.setTokenC5CF6A9EB1465D3AA6FB2(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-C5CF6A9EB1465D3AA6FB2"));
        x.setToken52486AA7D796B2255BFAC(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-52486AA7D796B2255BFAC"));
        x.setTokenB5C1EE76A29C4B9565FA4(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-B5C1EE76A29C4B9565FA4"));
        x.setToken484BB1EF60EDADE1B5F87(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-484BB1EF60EDADE1B5F87"));
        x.setTokenCC0C3139115704DDCD9B5(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-CC0C3139115704DDCD9B5"));
        x.setTokenF982C7EC74EC42B045292(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-F982C7EC74EC42B045292"));
        x.setTokenE21184507C5F3D50DB6B7(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E21184507C5F3D50DB6B7"));
        x.setTokenD45E9BEA4A13EF51DEBAA(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-D45E9BEA4A13EF51DEBAA"));
        x.setTokenB6862EBB8098F3A7844B2(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-B6862EBB8098F3A7844B2"));
        x.setTokenE4172A6C64523DEA10F86(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E4172A6C64523DEA10F86"));
        x.setTokenA95061722FE9A77D1DFBF(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-A95061722FE9A77D1DFBF"));
        x.setToken5B69AE3AA1EF011AAD4B3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-5B69AE3AA1EF011AAD4B3"));
        x.setToken66A3AAAD4DD83FCA1879F(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-66A3AAAD4DD83FCA1879F"));
        x.setTokenF8E4C5685995705F88B92(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-F8E4C5685995705F88B92"));
        x.setTokenC00E691B0A55A2DD43EB8(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-C00E691B0A55A2DD43EB8"));
        x.setToken9F9B02979A0DF3CC4778D(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9F9B02979A0DF3CC4778D"));
        x.setTokenDC19D53DD6052509AD1A3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-DC19D53DD6052509AD1A3"));
        x.setToken4AA54B21F152FC8DF76AF(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-4AA54B21F152FC8DF76AF"));
        x.setToken0A1129926CF5AB0429CBF(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-0A1129926CF5AB0429CBF"));
        x.setTokenDD5788037C4E041210AA5(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-DD5788037C4E041210AA5"));
        x.setTokenAD10645A4F87DE5EB0BAE(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-AD10645A4F87DE5EB0BAE"));
        x.setTokenEB8B0C94A2755E7867D88(MLBJson::get_optional<MLBJson::Token>(
            j, "token-EB8B0C94A2755E7867D88"));
        x.setToken070C5B4CF3C6A0525EF8A(MLBJson::get_optional<MLBJson::Token>(
            j, "token-070C5B4CF3C6A0525EF8A"));
        x.setToken2005A2B8966B82D1465B0(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-2005A2B8966B82D1465B0"));
        x.setTokenEEC2396B3AA201D183BB2(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-EEC2396B3AA201D183BB2"));
        x.setToken6F19EA16BAF005F8A9890(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-6F19EA16BAF005F8A9890"));
        x.setToken6D2EAF6B75B43DAFAE6B5(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-6D2EAF6B75B43DAFAE6B5"));
        x.setToken22D7AA24310E5C01DD7A6(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-22D7AA24310E5C01DD7A6"));
        x.setTokenB073BFD6F6F1A54561AAA(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-B073BFD6F6F1A54561AAA"));
        x.setTokenDC4D65D0323293BD9FFBE(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-DC4D65D0323293BD9FFBE"));
        x.setToken864AD60BCF6F538F88098(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-864AD60BCF6F538F88098"));
        x.setToken0A5BB893872F8C8C67DB9(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-0A5BB893872F8C8C67DB9"));
        x.setTokenBE0C2097C4F2C19F66CA2(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-BE0C2097C4F2C19F66CA2"));
        x.setToken4BFDDDF8D2722BCE14B9E(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-4BFDDDF8D2722BCE14B9E"));
        x.setTokenD54C011E1AB9599CC109C(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-D54C011E1AB9599CC109C"));
        x.setTokenD98EE3E8307B8F045AFB2(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-D98EE3E8307B8F045AFB2"));
        x.setTokenF09F92BD69607DA9FA58A(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-F09F92BD69607DA9FA58A"));
        x.setToken8895755EBF6C843217193(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-8895755EBF6C843217193"));
        x.setToken4DAA1881652DB60C7A69D(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-4DAA1881652DB60C7A69D"));
        x.setToken5CE56514A2C581E3548BB(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-5CE56514A2C581E3548BB"));
        x.setToken5286121206A18BC880CA1(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-5286121206A18BC880CA1"));
        x.setToken0BC3D6C3440A378947E9E(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-0BC3D6C3440A378947E9E"));
        x.setToken1017E26B4547892961C93(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-1017E26B4547892961C93"));
        x.setTokenF97DBB4ABBD980541AC92(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-F97DBB4ABBD980541AC92"));
        x.setToken14FD201B1642E4F7C22AE(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-14FD201B1642E4F7C22AE"));
        x.setToken284542EA81AA0A8F9F3BA(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-284542EA81AA0A8F9F3BA"));
        x.setTokenDD6AB438DB39A46267791(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-DD6AB438DB39A46267791"));
        x.setToken914A425A0D1A67AE16FB4(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-914A425A0D1A67AE16FB4"));
        x.setToken2713B53B467F1FC0859A4(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-2713B53B467F1FC0859A4"));
        x.setToken6AA83D1F06D61FA4B04A0(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-6AA83D1F06D61FA4B04A0"));
        x.setTokenEB80AFBF5ECC14E2B7A97(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-EB80AFBF5ECC14E2B7A97"));
        x.setTokenBC7FA51814A6539D0E198(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-BC7FA51814A6539D0E198"));
        x.setTokenF29ABE717AA237771A58D(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-F29ABE717AA237771A58D"));
        x.setTokenABC0CCBD80F4B6A73E183(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-ABC0CCBD80F4B6A73E183"));
        x.setToken91A96AB72040DB15F0889(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-91A96AB72040DB15F0889"));
        x.setToken02AE741A1216657EB1EA3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-02AE741A1216657EB1EA3"));
        x.setToken525BAB7BA21A8C4171196(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-525BAB7BA21A8C4171196"));
        x.setTokenC3E6904C99D6546B4D1A6(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-C3E6904C99D6546B4D1A6"));
        x.setToken3B4A3A61505C0DAB9B296(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-3B4A3A61505C0DAB9B296"));
        x.setToken131E682AB43965E3CD08D(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-131E682AB43965E3CD08D"));
        x.setTokenCD041A7D69BDD9C7BE3BB(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CD041A7D69BDD9C7BE3BB"));
        x.setToken05947572D06DE1DB8A298(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-05947572D06DE1DB8A298"));
        x.setToken40A59E33FB628C84D12A6(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-40A59E33FB628C84D12A6"));
        x.setToken81D360AE1966FE4A13498(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-81D360AE1966FE4A13498"));
        x.setToken7F4D4B46F0D3F3E6B948B(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-7F4D4B46F0D3F3E6B948B"));
        x.setTokenCD527524FFFCC134E68AD(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CD527524FFFCC134E68AD"));
        x.setToken09331C5A2FC68D6A37C8C(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-09331C5A2FC68D6A37C8C"));
        x.setToken5E8B97B8BC1CCFE672D84(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-5E8B97B8BC1CCFE672D84"));
        x.setToken1919A40BACD45BF456583(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-1919A40BACD45BF456583"));
        x.setTokenCF7DBB43C1BEC8B7E0583(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CF7DBB43C1BEC8B7E0583"));
        x.setTokenF9E4FCCF2958D99771DB5(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-F9E4FCCF2958D99771DB5"));
        x.setToken6EA6D99DA254E66ECA4BF(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-6EA6D99DA254E66ECA4BF"));
        x.setToken325C6E6F0D4C917F612AC(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-325C6E6F0D4C917F612AC"));
        x.setTokenC95E7E943D1FADFDB65A2(MLBJson::get_optional<MLBJson::Token>(
            j, "token-C95E7E943D1FADFDB65A2"));
        x.setTokenA930040748B7AD6919CB7(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-A930040748B7AD6919CB7"));
        x.setToken8BC82DBF7A9FF9D0E9795(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-8BC82DBF7A9FF9D0E9795"));
        x.setToken2D1004923EAF1526F8C81(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-2D1004923EAF1526F8C81"));
        x.setToken0C2DC1EE6F9A4340DFCA2(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-0C2DC1EE6F9A4340DFCA2"));
        x.setTokenDA8C7775F48B125F296AA(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-DA8C7775F48B125F296AA"));
        x.setTokenC079D392173F6252A9B96(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-C079D392173F6252A9B96"));
        x.setToken30AAEC5419E5CFBE0619B(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-30AAEC5419E5CFBE0619B"));
        x.setToken51C9117EDCCFBD4113183(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-51C9117EDCCFBD4113183"));
        x.setToken1A23A0729B946F42B568D(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-1A23A0729B946F42B568D"));
        x.setToken8D1C936FAD8E7FB2960A3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-8D1C936FAD8E7FB2960A3"));
        x.setTokenAE13DCA77AB5E5C238D96(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-AE13DCA77AB5E5C238D96"));
        x.setToken965804858147E711BBDA7(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-965804858147E711BBDA7"));
        x.setTokenCED72F9484959B5E5E8A3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CED72F9484959B5E5E8A3"));
        x.setToken748E8715DE7C703B363BD(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-748E8715DE7C703B363BD"));
        x.setTokenC1AA59A330DD13689138B(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-C1AA59A330DD13689138B"));
        x.setTokenDA38780E0D36911690096(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-DA38780E0D36911690096"));
        x.setTokenE9BAFFD7C98371BA1389D(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E9BAFFD7C98371BA1389D"));
        x.setToken4916780C4CF9BD3B22099(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-4916780C4CF9BD3B22099"));
        x.setToken710FCFBA6F2FE3A761E99(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-710FCFBA6F2FE3A761E99"));
        x.setTokenA8B1CBDAB3AEBB9A166A2(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-A8B1CBDAB3AEBB9A166A2"));
        x.setToken71491BF388DB005F10385(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-71491BF388DB005F10385"));
        x.setToken5D62DC906634BE78EFCB4(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-5D62DC906634BE78EFCB4"));
        x.setTokenAA104BAE32C34D8AFA1A2(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-AA104BAE32C34D8AFA1A2"));
        x.setToken6702818DD29E09D9A22A7(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-6702818DD29E09D9A22A7"));
        x.setToken99BC3D2DE1717F82E2999(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-99BC3D2DE1717F82E2999"));
        x.setTokenB3E5E87E867AE2D9B27AC(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-B3E5E87E867AE2D9B27AC"));
        x.setToken252B7A2AD40FEA145BD85(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-252B7A2AD40FEA145BD85"));
        x.setTokenE8FDD64E18F3710D7EE89(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E8FDD64E18F3710D7EE89"));
        x.setTokenDC53EE2DE0CA847341D8B(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-DC53EE2DE0CA847341D8B"));
        x.setToken1A7FC9AA0C41A32752294(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-1A7FC9AA0C41A32752294"));
        x.setToken5E258FBC355B5959040BC(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-5E258FBC355B5959040BC"));
        x.setToken0676E8BC26CADB6BAD3AA(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-0676E8BC26CADB6BAD3AA"));
        x.setToken43A0D255D3D202BDEFCB3(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-43A0D255D3D202BDEFCB3"));
        x.setToken2753FA17589D44632BB9F(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-2753FA17589D44632BB9F"));
        x.setToken72D8015C5A42F10EC718C(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-72D8015C5A42F10EC718C"));
        x.setToken537662B35E180A527F7A0(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-537662B35E180A527F7A0"));
        x.setTokenE0E410C8AC996EB11CB85(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-E0E410C8AC996EB11CB85"));
        x.setToken9B1067E1332C4D152B1AD(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9B1067E1332C4D152B1AD"));
        x.setToken1763F37EE500EF4E84E83(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-1763F37EE500EF4E84E83"));
        x.setTokenCD4BEFC7BB8BD00D5A5A9(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CD4BEFC7BB8BD00D5A5A9"));
        x.setToken7A458795BD4B0D95651B7(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-7A458795BD4B0D95651B7"));
        x.setToken59C91F284D3472DE5B08D(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-59C91F284D3472DE5B08D"));
        x.setToken2F1CE8C3537D39C3B42A3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-2F1CE8C3537D39C3B42A3"));
        x.setToken0055D3A7A18B4580C8F8C(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-0055D3A7A18B4580C8F8C"));
        x.setTokenE34215A0C5DCD9035DC83(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E34215A0C5DCD9035DC83"));
        x.setToken10D15272527BD16B97E84(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-10D15272527BD16B97E84"));
        x.setToken0DE01F3020C5A5A702F9A(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-0DE01F3020C5A5A702F9A"));
        x.setToken9A446B4684FA2B2656ABE(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9A446B4684FA2B2656ABE"));
        x.setTokenCD7E5318FC7C9816CD7B0(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CD7E5318FC7C9816CD7B0"));
        x.setToken013C382D3D890D3B1FEA7(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-013C382D3D890D3B1FEA7"));
        x.setToken845B0B9C1B8874A7C2CB6(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-845B0B9C1B8874A7C2CB6"));
        x.setTokenB5E715791898691F8D780(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-B5E715791898691F8D780"));
        x.setTokenC159A044375814C6307A2(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-C159A044375814C6307A2"));
        x.setToken06D8C451D01C967B2A889(MLBJson::get_optional<MLBJson::Token>(
            j, "token-06D8C451D01C967B2A889"));
        x.setToken4947D300F5746CB9327A9(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-4947D300F5746CB9327A9"));
        x.setTokenDBC3DD3DD9962086D98B8(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-DBC3DD3DD9962086D98B8"));
        x.setToken90B46B4771085F9F64087(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-90B46B4771085F9F64087"));
        x.setTokenDA864C7498ED439B5D095(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-DA864C7498ED439B5D095"));
        x.setToken8EDE4E47E55E8945128AC(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-8EDE4E47E55E8945128AC"));
        x.setToken4F9CEBFCB2BCB7C1F93AE(MLBJson::get_optional<MLBJson::Token>(
            j, "token-4F9CEBFCB2BCB7C1F93AE"));
        x.setTokenC0E5BD48806EA05D8E1B3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-C0E5BD48806EA05D8E1B3"));
        x.setTokenA713AE88B171CF6DE2584(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-A713AE88B171CF6DE2584"));
        x.setToken71FE836A3546F7800028F(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-71FE836A3546F7800028F"));
        x.setTokenBF85C9CB2643D2241AFBE(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-BF85C9CB2643D2241AFBE"));
        x.setTokenED59CC7C7EBD1C981D9AD(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-ED59CC7C7EBD1C981D9AD"));
        x.setTokenCCF87B3D65FD49EECC6A4(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CCF87B3D65FD49EECC6A4"));
        x.setToken238BE16B560DAFB40A8B3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-238BE16B560DAFB40A8B3"));
        x.setToken88767604C712FA84DE2B4(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-88767604C712FA84DE2B4"));
        x.setToken896C4E49DF74696BBBB8E(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-896C4E49DF74696BBBB8E"));
        x.setToken2884443F1CDB74F7E97A7(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-2884443F1CDB74F7E97A7"));
        x.setTokenCD0D1A32B252CB1328B9A(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-CD0D1A32B252CB1328B9A"));
        x.setToken213D74984AAA195477685(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-213D74984AAA195477685"));
        x.setToken594687C9B2CA65E5CB496(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-594687C9B2CA65E5CB496"));
        x.setTokenEC6AA0C48EEA99823E1A2(MLBJson::get_optional<MLBJson::Token>(
            j, "token-EC6AA0C48EEA99823E1A2"));
        x.setToken896463C5DE287BB120E80(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-896463C5DE287BB120E80"));
        x.setTokenB7B473A156B5AFEF56FA3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-B7B473A156B5AFEF56FA3"));
        x.setTokenBA252399CE2C5F9194790(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-BA252399CE2C5F9194790"));
        x.setTokenD65725A7C3014B742D999(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-D65725A7C3014B742D999"));
        x.setToken88AB56442BF560EA449A1(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-88AB56442BF560EA449A1"));
        x.setToken9E6C96FBA7639E73BCE9D(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9E6C96FBA7639E73BCE9D"));
        x.setToken4201CDF79A2F9160671B3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-4201CDF79A2F9160671B3"));
        x.setToken868303FF0484A110D1293(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-868303FF0484A110D1293"));
        x.setToken85AD0DE8698EA728E5D9C(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-85AD0DE8698EA728E5D9C"));
        x.setTokenFCF78BB01006B90686088(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-FCF78BB01006B90686088"));
        x.setTokenA2BD2B5293660FB1173A6(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-A2BD2B5293660FB1173A6"));
        x.setToken01D8ECCF9F69D3E9FC7B1(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-01D8ECCF9F69D3E9FC7B1"));
        x.setToken7976D7BDB91692136A1AB(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-7976D7BDB91692136A1AB"));
        x.setTokenA86DB4585C3D45CB353AD(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-A86DB4585C3D45CB353AD"));
        x.setToken71EB4680E8A3A35BA0FB0(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-71EB4680E8A3A35BA0FB0"));
        x.setTokenEEAF0DEE6AD40E74DA5BC(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-EEAF0DEE6AD40E74DA5BC"));
        x.setTokenEA6E3BE35693BB6FB8BB7(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-EA6E3BE35693BB6FB8BB7"));
        x.setTokenCEA2074211CEEBD9B5DB3(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CEA2074211CEEBD9B5DB3"));
        x.setToken1C733F07F13173D19B29F(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-1C733F07F13173D19B29F"));
        x.setToken20C940B34447AB12CCEA8(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-20C940B34447AB12CCEA8"));
        x.setToken44ABE8B7288C4D59102B5(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-44ABE8B7288C4D59102B5"));
        x.setTokenEEC6944070EA265B950B0(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-EEC6944070EA265B950B0"));
        x.setToken4AFD25AD6666299F2A88B(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-4AFD25AD6666299F2A88B"));
        x.setToken6669C3AABD6369A1AED82(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-6669C3AABD6369A1AED82"));
        x.setToken5B280CB8A69F3D0902EA4(MLBJson::get_optional<MLBJson::Token>(
            j, "token-5B280CB8A69F3D0902EA4"));
        x.setTokenCDFF7828935B02B2CDF86(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-CDFF7828935B02B2CDF86"));
        x.setTokenAF8113E8B8049BAEB73B1(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-AF8113E8B8049BAEB73B1"));
        x.setToken696B050B75268E575EE84(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-696B050B75268E575EE84"));
        x.setToken892A51A637EF5A550FDBA(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-892A51A637EF5A550FDBA"));
        x.setToken0DE090A2C87A61162BBA4(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-0DE090A2C87A61162BBA4"));
        x.setToken63CC3A387F5BAEF69D4A7(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-63CC3A387F5BAEF69D4A7"));
        x.setToken0B1C3C68043A4F4B61F9F(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-0B1C3C68043A4F4B61F9F"));
        x.setToken0A4486D1E21D43E961BA6(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-0A4486D1E21D43E961BA6"));
        x.setToken5282457FF22ABFDE400B4(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-5282457FF22ABFDE400B4"));
        x.setTokenD8774B9492D7CBFC37CB8(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-D8774B9492D7CBFC37CB8"));
        x.setToken4B5D845A389A0EE19AABF(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-4B5D845A389A0EE19AABF"));
        x.setTokenE6D5489CE13AD84D8E7B7(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E6D5489CE13AD84D8E7B7"));
        x.setToken9FF026A883F738C0B0CB9(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9FF026A883F738C0B0CB9"));
        x.setTokenCA96E1DBD4F7E72EED48D(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CA96E1DBD4F7E72EED48D"));
        x.setToken0D2CB48596748A6B4BFBA(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-0D2CB48596748A6B4BFBA"));
        x.setToken434F3160A979CA1009882(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-434F3160A979CA1009882"));
        x.setToken9220F57D2902D463A1A8D(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9220F57D2902D463A1A8D"));
        x.setToken096809C9884ED117FB9B6(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-096809C9884ED117FB9B6"));
        x.setToken0189CF14C1ABB9E38D288(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-0189CF14C1ABB9E38D288"));
        x.setTokenB044BAAF3986B432AE7BF(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-B044BAAF3986B432AE7BF"));
        x.setTokenB7FA499A68198D093D8A2(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-B7FA499A68198D093D8A2"));
        x.setToken438FF67AE1F17D825FAB5(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-438FF67AE1F17D825FAB5"));
        x.setToken352D769B1B3BB61DBAFBB(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-352D769B1B3BB61DBAFBB"));
        x.setTokenB0F4CB473A8FDBB9CE692(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-B0F4CB473A8FDBB9CE692"));
        x.setTokenCF772D023E3AFAE164899(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CF772D023E3AFAE164899"));
        x.setTokenEC7A4FC879CE357C2DF84(MLBJson::get_optional<MLBJson::Token>(
            j, "token-EC7A4FC879CE357C2DF84"));
        x.setToken089FB68037C80FE98FCAA(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-089FB68037C80FE98FCAA"));
        x.setToken346CF28DB5A65D132898E(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-346CF28DB5A65D132898E"));
        x.setTokenDA48586079FD76F4A9FAD(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-DA48586079FD76F4A9FAD"));
        x.setToken947AF2755679C774793BA(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-947AF2755679C774793BA"));
        x.setTokenF07D4E665D02F4187439E(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-F07D4E665D02F4187439E"));
        x.setToken9E429B12B9261F6A8A489(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9E429B12B9261F6A8A489"));
        x.setTokenE87D96060B9E2D539DC9B(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-E87D96060B9E2D539DC9B"));
        x.setToken0FA39B41B19A62959098F(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-0FA39B41B19A62959098F"));
        x.setToken1803E0AC70A0D57BBA981(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-1803E0AC70A0D57BBA981"));
        x.setToken48A9BB431CC7D43FD5BA8(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-48A9BB431CC7D43FD5BA8"));
        x.setTokenD8AC4F4104AD455C85A84(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-D8AC4F4104AD455C85A84"));
        x.setTokenBF1DEF94AAFC697A6F9BA(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-BF1DEF94AAFC697A6F9BA"));
        x.setToken7D08480AD0B453BE029A8(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-7D08480AD0B453BE029A8"));
        x.setToken4473A490C2ECEA90DAAB2(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-4473A490C2ECEA90DAAB2"));
        x.setTokenB17711FF64A6F6F06299D(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-B17711FF64A6F6F06299D"));
        x.setToken844BFDA4BE916BD54A3AA(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-844BFDA4BE916BD54A3AA"));
        x.setToken23229682C74347EEB8886(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-23229682C74347EEB8886"));
        x.setToken60E6C57473CB0C88A3E86(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-60E6C57473CB0C88A3E86"));
        x.setToken8C31165AE39E790CCD7B8(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-8C31165AE39E790CCD7B8"));
        x.setTokenFE355BF81FC13A6A0DDAE(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-FE355BF81FC13A6A0DDAE"));
        x.setTokenCF3855D906085F5BBFB8B(MLBJson::get_optional<MLBJson::Token>(
            j, "token-CF3855D906085F5BBFB8B"));
        x.setToken9F00C7C0F02FB6B6BDB80(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-9F00C7C0F02FB6B6BDB80"));
        x.setToken672CC221DCD193EEA0093(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-672CC221DCD193EEA0093"));
        x.setToken682906AC7B7E242CFC883(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-682906AC7B7E242CFC883"));
        x.setToken3D725B01FB7B9FA90E387(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-3D725B01FB7B9FA90E387"));
        x.setToken6A8D9E562B7D9BCC22487(MLBJson::get_optional<MLBJson::Token>(
            j, "token-6A8D9E562B7D9BCC22487"));
        x.setTokenFCFD60AF5972635E239A1(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-FCFD60AF5972635E239A1"));
        x.setToken44257D2BB1EB83445748B(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-44257D2BB1EB83445748B"));
        x.setTokenC081C1B31AD23306729BC(
            MLBJson::get_optional<MLBJson::ChiangMaiGoose>(
                j, "token-C081C1B31AD23306729BC"));
        x.setToken91EE07D52D132C0291AA9(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-91EE07D52D132C0291AA9"));
        x.setToken463C9F3509B4B3CE21890(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-463C9F3509B4B3CE21890"));
        x.setTokenA8AE1C4637E3977ED139C(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-A8AE1C4637E3977ED139C"));
        x.setToken072340E8F68E6230FB595(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-072340E8F68E6230FB595"));
        x.setTokenAFEABC74E014E1FDCA189(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-AFEABC74E014E1FDCA189"));
        x.setToken8C03099B0BF7559E4CC8B(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-8C03099B0BF7559E4CC8B"));
        x.setTokenCAD830A007BF99AE22588(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-CAD830A007BF99AE22588"));
        x.setToken803EDA85AD6E2152498B9(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-803EDA85AD6E2152498B9"));
        x.setToken261F79B544B15F18D90BC(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-261F79B544B15F18D90BC"));
        x.setToken57FF4186B72441359A28C(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-57FF4186B72441359A28C"));
        x.setToken9636866E27CE8589EBCAF(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-9636866E27CE8589EBCAF"));
        x.setToken0651D7AAA332194B08DBE(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-0651D7AAA332194B08DBE"));
        x.setTokenA158381332191727F40AB(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-A158381332191727F40AB"));
        x.setToken7D115BFFC746C4DE901B1(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-7D115BFFC746C4DE901B1"));
        x.setTokenDCEC566E79614AE22F599(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-DCEC566E79614AE22F599"));
        x.setTokenD7ECF91124B8871B9D484(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-D7ECF91124B8871B9D484"));
        x.setToken97EFEDD8F2A074CEAAE88(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-97EFEDD8F2A074CEAAE88"));
        x.setToken3E9C3D0C2A9A1151B7B88(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-3E9C3D0C2A9A1151B7B88"));
        x.setToken39AC0A81B17950CF2D2B5(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-39AC0A81B17950CF2D2B5"));
        x.setTokenAEC432518E3CF5FDE4FB5(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-AEC432518E3CF5FDE4FB5"));
        x.setToken5A9C312E1F012AE978784(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-5A9C312E1F012AE978784"));
        x.setTokenFBD4128927E1E68A54A81(MLBJson::get_optional<MLBJson::Token>(
            j, "token-FBD4128927E1E68A54A81"));
        x.setToken910E582093166C1D0DF80(
            MLBJson::get_optional<MLBJson::ArakGroundhog>(
                j, "token-910E582093166C1D0DF80"));
    }

    inline void to_json(json &j, const MLBJson::TokenData &x) {
        j = json::object();
        j["token-23730D7C7D9AA9F7C5E85"] = x.getToken23730D7C7D9AA9F7C5E85();
        j["token-C91ACC313F379CD2B52B8"] = x.getTokenC91ACC313F379CD2B52B8();
        j["token-E6D877BB9EC2A8D9D039C"] = x.getTokenE6D877BB9EC2A8D9D039C();
        j["token-56D431904961877F1F5BE"] = x.getToken56D431904961877F1F5BE();
        j["token-412467956BE5CDFFAF4B2"] = x.getToken412467956BE5CDFFAF4B2();
        j["token-5DAE442BC99D96A8B96BF"] = x.getToken5DAE442BC99D96A8B96BF();
        j["token-9FA7F2E5B8A9875EE0B94"] = x.getToken9FA7F2E5B8A9875EE0B94();
        j["token-460084A221436934CEBBE"] = x.getToken460084A221436934CEBBE();
        j["token-275E1DD943030C5B5FB9D"] = x.getToken275E1DD943030C5B5FB9D();
        j["token-212DE831C266CB42802BC"] = x.getToken212DE831C266CB42802BC();
        j["token-E09A5C6B0D7BB2C4551B6"] = x.getTokenE09A5C6B0D7BB2C4551B6();
        j["token-3055644DABCB711618A81"] = x.getToken3055644DABCB711618A81();
        j["token-8D9DAA42490BC0B227599"] = x.getToken8D9DAA42490BC0B227599();
        j["token-760E83788F63C48DDF7AD"] = x.getToken760E83788F63C48DDF7AD();
        j["token-ACEB6A8D4FD80CC07ECA7"] = x.getTokenACEB6A8D4FD80CC07ECA7();
        j["token-91AD363841ED76C7060A7"] = x.getToken91AD363841ED76C7060A7();
        j["token-68CA80F95ED6B4A6A77A8"] = x.getToken68CA80F95ED6B4A6A77A8();
        j["token-55F7368BE04958F4173A0"] = x.getToken55F7368BE04958F4173A0();
        j["token-64CD4F91E838690A6C98F"] = x.getToken64CD4F91E838690A6C98F();
        j["token-5F3A93356640B35066AB0"] = x.getToken5F3A93356640B35066AB0();
        j["token-F352FC9E205DF80BBB9A1"] = x.getTokenF352FC9E205DF80BBB9A1();
        j["token-CC4A8F62FBB98029F49BA"] = x.getTokenCC4A8F62FBB98029F49BA();
        j["token-9C784204BF18430ED5BB4"] = x.getToken9C784204BF18430ED5BB4();
        j["token-F1B435C49B4E098FEC386"] = x.getTokenF1B435C49B4E098FEC386();
        j["token-549ED10CFB146448E9CBD"] = x.getToken549ED10CFB146448E9CBD();
        j["token-FC81372023C05244CC0BE"] = x.getTokenFC81372023C05244CC0BE();
        j["token-A01CA209CC332D81E0489"] = x.getTokenA01CA209CC332D81E0489();
        j["token-F7330F5A16C0560ED6CA4"] = x.getTokenF7330F5A16C0560ED6CA4();
        j["token-E673EA12C41DA76D45188"] = x.getTokenE673EA12C41DA76D45188();
        j["token-2836C14E0570C3E685693"] = x.getToken2836C14E0570C3E685693();
        j["token-234DA65DCF4B07EE7FAB9"] = x.getToken234DA65DCF4B07EE7FAB9();
        j["token-3AF0395C10670B84922A4"] = x.getToken3AF0395C10670B84922A4();
        j["token-1991AA23E3C62AA661FAC"] = x.getToken1991AA23E3C62AA661FAC();
        j["token-8E0C32852C68A118C76A7"] = x.getToken8E0C32852C68A118C76A7();
        j["token-C23474240906E85A9AF97"] = x.getTokenC23474240906E85A9AF97();
        j["token-66285580C871C449AA2AF"] = x.getToken66285580C871C449AA2AF();
        j["token-8584EAFA2CD964D3F359D"] = x.getToken8584EAFA2CD964D3F359D();
        j["token-6745E57514242D6D69782"] = x.getToken6745E57514242D6D69782();
        j["token-38928BB57CE50F1C31FAD"] = x.getToken38928BB57CE50F1C31FAD();
        j["token-9C0B2BEAA6DFD31524EAB"] = x.getToken9C0B2BEAA6DFD31524EAB();
        j["token-1CD29147D64EBEEBB8F9F"] = x.getToken1CD29147D64EBEEBB8F9F();
        j["token-F4B9964747E6117A18D9E"] = x.getTokenF4B9964747E6117A18D9E();
        j["token-9537EB58E6571B5018A88"] = x.getToken9537EB58E6571B5018A88();
        j["token-E3D3B4D9DE79219AF61B5"] = x.getTokenE3D3B4D9DE79219AF61B5();
        j["token-E44A9E703B514FE9DCF8F"] = x.getTokenE44A9E703B514FE9DCF8F();
        j["token-6A498B883DC78DF271CAB"] = x.getToken6A498B883DC78DF271CAB();
        j["token-457F3E65BD903C1FC8AAE"] = x.getToken457F3E65BD903C1FC8AAE();
        j["token-B952619F7911BD23953BD"] = x.getTokenB952619F7911BD23953BD();
        j["token-5FB0AA57C2A4D9A752093"] = x.getToken5FB0AA57C2A4D9A752093();
        j["token-403A70FFCF76D500D0492"] = x.getToken403A70FFCF76D500D0492();
        j["token-2BF7F992E24CB42B8F497"] = x.getToken2BF7F992E24CB42B8F497();
        j["token-D11FB99FC582DA9D129A9"] = x.getTokenD11FB99FC582DA9D129A9();
        j["token-37F9A03CEE7D128E78F8E"] = x.getToken37F9A03CEE7D128E78F8E();
        j["token-F1AC4F490B957534BC2BA"] = x.getTokenF1AC4F490B957534BC2BA();
        j["token-EE5431A399A2EA755F985"] = x.getTokenEE5431A399A2EA755F985();
        j["token-7C7D7205D6AF7E6A35AB6"] = x.getToken7C7D7205D6AF7E6A35AB6();
        j["token-7FEFC21E98FBD0DE662BE"] = x.getToken7FEFC21E98FBD0DE662BE();
        j["token-5F4FCB0691087ABE512A6"] = x.getToken5F4FCB0691087ABE512A6();
        j["token-73B814D8560F9AB7FA181"] = x.getToken73B814D8560F9AB7FA181();
        j["token-1BE5802AEE0CBAB99B882"] = x.getToken1BE5802AEE0CBAB99B882();
        j["token-9F7A70A34D6F5C0FB3E88"] = x.getToken9F7A70A34D6F5C0FB3E88();
        j["token-9BBD87FF0925CB6CBA2A6"] = x.getToken9BBD87FF0925CB6CBA2A6();
        j["token-E973C7D95C067E9422E89"] = x.getTokenE973C7D95C067E9422E89();
        j["token-4A8B125DFC764AAB727A7"] = x.getToken4A8B125DFC764AAB727A7();
        j["token-05E57D99C3CD69F05C7BC"] = x.getToken05E57D99C3CD69F05C7BC();
        j["token-F889173B1228AC1E84FA3"] = x.getTokenF889173B1228AC1E84FA3();
        j["token-DD46C0D463EB26DE473B5"] = x.getTokenDD46C0D463EB26DE473B5();
        j["token-E76ABAC6694B03E9CE087"] = x.getTokenE76ABAC6694B03E9CE087();
        j["token-D28FD03E38ACE143DF1BA"] = x.getTokenD28FD03E38ACE143DF1BA();
        j["token-020A9754A3089AC08B48C"] = x.getToken020A9754A3089AC08B48C();
        j["token-5F5D6D55FC1A1735A8C91"] = x.getToken5F5D6D55FC1A1735A8C91();
        j["token-CEA6AB430FA895B14D38C"] = x.getTokenCEA6AB430FA895B14D38C();
        j["token-69F211937F19241D2719A"] = x.getToken69F211937F19241D2719A();
        j["token-B23C7403A039BD742F790"] = x.getTokenB23C7403A039BD742F790();
        j["token-7FFE1F12B5DE3C78BD5B3"] = x.getToken7FFE1F12B5DE3C78BD5B3();
        j["token-C2FB3EC7DD3C5A14987A4"] = x.getTokenC2FB3EC7DD3C5A14987A4();
        j["token-189330D6BFCA399608FB4"] = x.getToken189330D6BFCA399608FB4();
        j["token-AF767EF443126B3CCD8AF"] = x.getTokenAF767EF443126B3CCD8AF();
        j["token-773BE241B74FA7597F780"] = x.getToken773BE241B74FA7597F780();
        j["token-1BE823E3464AD53321FB1"] = x.getToken1BE823E3464AD53321FB1();
        j["token-5F162503444CFEC22AF81"] = x.getToken5F162503444CFEC22AF81();
        j["token-13ACDBA5AF1CC23DF99BA"] = x.getToken13ACDBA5AF1CC23DF99BA();
        j["token-9FDF39287E87C1B324894"] = x.getToken9FDF39287E87C1B324894();
        j["token-A32E4613028FD614C2992"] = x.getTokenA32E4613028FD614C2992();
        j["token-A433BA409058D6BE952A5"] = x.getTokenA433BA409058D6BE952A5();
        j["token-7CF34D79E5F77AD7595B5"] = x.getToken7CF34D79E5F77AD7595B5();
        j["token-92B8DA5E1E3E67C80D793"] = x.getToken92B8DA5E1E3E67C80D793();
        j["token-75BD980A2FAC6679C9CA9"] = x.getToken75BD980A2FAC6679C9CA9();
        j["token-804528C0EDB6908B0B899"] = x.getToken804528C0EDB6908B0B899();
        j["token-CBA976567E4283E3E9E9B"] = x.getTokenCBA976567E4283E3E9E9B();
        j["token-99C6A24D2A561187A77BA"] = x.getToken99C6A24D2A561187A77BA();
        j["token-25B4946A8DC84F7E5F0AA"] = x.getToken25B4946A8DC84F7E5F0AA();
        j["token-C75FA378013EC28E08CA9"] = x.getTokenC75FA378013EC28E08CA9();
        j["token-4B8879991B0C58A8DE786"] = x.getToken4B8879991B0C58A8DE786();
        j["token-5DC7CA1D490AB35523D9E"] = x.getToken5DC7CA1D490AB35523D9E();
        j["token-7D071A1FBCAE3D2EC0C90"] = x.getToken7D071A1FBCAE3D2EC0C90();
        j["token-D9214DB82A79855D1859D"] = x.getTokenD9214DB82A79855D1859D();
        j["token-410A7675F420C35808D87"] = x.getToken410A7675F420C35808D87();
        j["token-A9E0E34E0D049ABBC058C"] = x.getTokenA9E0E34E0D049ABBC058C();
        j["token-6606AC90A18517646E98C"] = x.getToken6606AC90A18517646E98C();
        j["token-31DC1509DB328F11CE0AC"] = x.getToken31DC1509DB328F11CE0AC();
        j["token-2257B2C2C7580FB792CA6"] = x.getToken2257B2C2C7580FB792CA6();
        j["token-9DF69821A140BE2EE72A7"] = x.getToken9DF69821A140BE2EE72A7();
        j["token-73FE56D22D475C7AEDDBC"] = x.getToken73FE56D22D475C7AEDDBC();
        j["token-C5CF6A9EB1465D3AA6FB2"] = x.getTokenC5CF6A9EB1465D3AA6FB2();
        j["token-52486AA7D796B2255BFAC"] = x.getToken52486AA7D796B2255BFAC();
        j["token-B5C1EE76A29C4B9565FA4"] = x.getTokenB5C1EE76A29C4B9565FA4();
        j["token-484BB1EF60EDADE1B5F87"] = x.getToken484BB1EF60EDADE1B5F87();
        j["token-CC0C3139115704DDCD9B5"] = x.getTokenCC0C3139115704DDCD9B5();
        j["token-F982C7EC74EC42B045292"] = x.getTokenF982C7EC74EC42B045292();
        j["token-E21184507C5F3D50DB6B7"] = x.getTokenE21184507C5F3D50DB6B7();
        j["token-D45E9BEA4A13EF51DEBAA"] = x.getTokenD45E9BEA4A13EF51DEBAA();
        j["token-B6862EBB8098F3A7844B2"] = x.getTokenB6862EBB8098F3A7844B2();
        j["token-E4172A6C64523DEA10F86"] = x.getTokenE4172A6C64523DEA10F86();
        j["token-A95061722FE9A77D1DFBF"] = x.getTokenA95061722FE9A77D1DFBF();
        j["token-5B69AE3AA1EF011AAD4B3"] = x.getToken5B69AE3AA1EF011AAD4B3();
        j["token-66A3AAAD4DD83FCA1879F"] = x.getToken66A3AAAD4DD83FCA1879F();
        j["token-F8E4C5685995705F88B92"] = x.getTokenF8E4C5685995705F88B92();
        j["token-C00E691B0A55A2DD43EB8"] = x.getTokenC00E691B0A55A2DD43EB8();
        j["token-9F9B02979A0DF3CC4778D"] = x.getToken9F9B02979A0DF3CC4778D();
        j["token-DC19D53DD6052509AD1A3"] = x.getTokenDC19D53DD6052509AD1A3();
        j["token-4AA54B21F152FC8DF76AF"] = x.getToken4AA54B21F152FC8DF76AF();
        j["token-0A1129926CF5AB0429CBF"] = x.getToken0A1129926CF5AB0429CBF();
        j["token-DD5788037C4E041210AA5"] = x.getTokenDD5788037C4E041210AA5();
        j["token-AD10645A4F87DE5EB0BAE"] = x.getTokenAD10645A4F87DE5EB0BAE();
        j["token-EB8B0C94A2755E7867D88"] = x.getTokenEB8B0C94A2755E7867D88();
        j["token-070C5B4CF3C6A0525EF8A"] = x.getToken070C5B4CF3C6A0525EF8A();
        j["token-2005A2B8966B82D1465B0"] = x.getToken2005A2B8966B82D1465B0();
        j["token-EEC2396B3AA201D183BB2"] = x.getTokenEEC2396B3AA201D183BB2();
        j["token-6F19EA16BAF005F8A9890"] = x.getToken6F19EA16BAF005F8A9890();
        j["token-6D2EAF6B75B43DAFAE6B5"] = x.getToken6D2EAF6B75B43DAFAE6B5();
        j["token-22D7AA24310E5C01DD7A6"] = x.getToken22D7AA24310E5C01DD7A6();
        j["token-B073BFD6F6F1A54561AAA"] = x.getTokenB073BFD6F6F1A54561AAA();
        j["token-DC4D65D0323293BD9FFBE"] = x.getTokenDC4D65D0323293BD9FFBE();
        j["token-864AD60BCF6F538F88098"] = x.getToken864AD60BCF6F538F88098();
        j["token-0A5BB893872F8C8C67DB9"] = x.getToken0A5BB893872F8C8C67DB9();
        j["token-BE0C2097C4F2C19F66CA2"] = x.getTokenBE0C2097C4F2C19F66CA2();
        j["token-4BFDDDF8D2722BCE14B9E"] = x.getToken4BFDDDF8D2722BCE14B9E();
        j["token-D54C011E1AB9599CC109C"] = x.getTokenD54C011E1AB9599CC109C();
        j["token-D98EE3E8307B8F045AFB2"] = x.getTokenD98EE3E8307B8F045AFB2();
        j["token-F09F92BD69607DA9FA58A"] = x.getTokenF09F92BD69607DA9FA58A();
        j["token-8895755EBF6C843217193"] = x.getToken8895755EBF6C843217193();
        j["token-4DAA1881652DB60C7A69D"] = x.getToken4DAA1881652DB60C7A69D();
        j["token-5CE56514A2C581E3548BB"] = x.getToken5CE56514A2C581E3548BB();
        j["token-5286121206A18BC880CA1"] = x.getToken5286121206A18BC880CA1();
        j["token-0BC3D6C3440A378947E9E"] = x.getToken0BC3D6C3440A378947E9E();
        j["token-1017E26B4547892961C93"] = x.getToken1017E26B4547892961C93();
        j["token-F97DBB4ABBD980541AC92"] = x.getTokenF97DBB4ABBD980541AC92();
        j["token-14FD201B1642E4F7C22AE"] = x.getToken14FD201B1642E4F7C22AE();
        j["token-284542EA81AA0A8F9F3BA"] = x.getToken284542EA81AA0A8F9F3BA();
        j["token-DD6AB438DB39A46267791"] = x.getTokenDD6AB438DB39A46267791();
        j["token-914A425A0D1A67AE16FB4"] = x.getToken914A425A0D1A67AE16FB4();
        j["token-2713B53B467F1FC0859A4"] = x.getToken2713B53B467F1FC0859A4();
        j["token-6AA83D1F06D61FA4B04A0"] = x.getToken6AA83D1F06D61FA4B04A0();
        j["token-EB80AFBF5ECC14E2B7A97"] = x.getTokenEB80AFBF5ECC14E2B7A97();
        j["token-BC7FA51814A6539D0E198"] = x.getTokenBC7FA51814A6539D0E198();
        j["token-F29ABE717AA237771A58D"] = x.getTokenF29ABE717AA237771A58D();
        j["token-ABC0CCBD80F4B6A73E183"] = x.getTokenABC0CCBD80F4B6A73E183();
        j["token-91A96AB72040DB15F0889"] = x.getToken91A96AB72040DB15F0889();
        j["token-02AE741A1216657EB1EA3"] = x.getToken02AE741A1216657EB1EA3();
        j["token-525BAB7BA21A8C4171196"] = x.getToken525BAB7BA21A8C4171196();
        j["token-C3E6904C99D6546B4D1A6"] = x.getTokenC3E6904C99D6546B4D1A6();
        j["token-3B4A3A61505C0DAB9B296"] = x.getToken3B4A3A61505C0DAB9B296();
        j["token-131E682AB43965E3CD08D"] = x.getToken131E682AB43965E3CD08D();
        j["token-CD041A7D69BDD9C7BE3BB"] = x.getTokenCD041A7D69BDD9C7BE3BB();
        j["token-05947572D06DE1DB8A298"] = x.getToken05947572D06DE1DB8A298();
        j["token-40A59E33FB628C84D12A6"] = x.getToken40A59E33FB628C84D12A6();
        j["token-81D360AE1966FE4A13498"] = x.getToken81D360AE1966FE4A13498();
        j["token-7F4D4B46F0D3F3E6B948B"] = x.getToken7F4D4B46F0D3F3E6B948B();
        j["token-CD527524FFFCC134E68AD"] = x.getTokenCD527524FFFCC134E68AD();
        j["token-09331C5A2FC68D6A37C8C"] = x.getToken09331C5A2FC68D6A37C8C();
        j["token-5E8B97B8BC1CCFE672D84"] = x.getToken5E8B97B8BC1CCFE672D84();
        j["token-1919A40BACD45BF456583"] = x.getToken1919A40BACD45BF456583();
        j["token-CF7DBB43C1BEC8B7E0583"] = x.getTokenCF7DBB43C1BEC8B7E0583();
        j["token-F9E4FCCF2958D99771DB5"] = x.getTokenF9E4FCCF2958D99771DB5();
        j["token-6EA6D99DA254E66ECA4BF"] = x.getToken6EA6D99DA254E66ECA4BF();
        j["token-325C6E6F0D4C917F612AC"] = x.getToken325C6E6F0D4C917F612AC();
        j["token-C95E7E943D1FADFDB65A2"] = x.getTokenC95E7E943D1FADFDB65A2();
        j["token-A930040748B7AD6919CB7"] = x.getTokenA930040748B7AD6919CB7();
        j["token-8BC82DBF7A9FF9D0E9795"] = x.getToken8BC82DBF7A9FF9D0E9795();
        j["token-2D1004923EAF1526F8C81"] = x.getToken2D1004923EAF1526F8C81();
        j["token-0C2DC1EE6F9A4340DFCA2"] = x.getToken0C2DC1EE6F9A4340DFCA2();
        j["token-DA8C7775F48B125F296AA"] = x.getTokenDA8C7775F48B125F296AA();
        j["token-C079D392173F6252A9B96"] = x.getTokenC079D392173F6252A9B96();
        j["token-30AAEC5419E5CFBE0619B"] = x.getToken30AAEC5419E5CFBE0619B();
        j["token-51C9117EDCCFBD4113183"] = x.getToken51C9117EDCCFBD4113183();
        j["token-1A23A0729B946F42B568D"] = x.getToken1A23A0729B946F42B568D();
        j["token-8D1C936FAD8E7FB2960A3"] = x.getToken8D1C936FAD8E7FB2960A3();
        j["token-AE13DCA77AB5E5C238D96"] = x.getTokenAE13DCA77AB5E5C238D96();
        j["token-965804858147E711BBDA7"] = x.getToken965804858147E711BBDA7();
        j["token-CED72F9484959B5E5E8A3"] = x.getTokenCED72F9484959B5E5E8A3();
        j["token-748E8715DE7C703B363BD"] = x.getToken748E8715DE7C703B363BD();
        j["token-C1AA59A330DD13689138B"] = x.getTokenC1AA59A330DD13689138B();
        j["token-DA38780E0D36911690096"] = x.getTokenDA38780E0D36911690096();
        j["token-E9BAFFD7C98371BA1389D"] = x.getTokenE9BAFFD7C98371BA1389D();
        j["token-4916780C4CF9BD3B22099"] = x.getToken4916780C4CF9BD3B22099();
        j["token-710FCFBA6F2FE3A761E99"] = x.getToken710FCFBA6F2FE3A761E99();
        j["token-A8B1CBDAB3AEBB9A166A2"] = x.getTokenA8B1CBDAB3AEBB9A166A2();
        j["token-71491BF388DB005F10385"] = x.getToken71491BF388DB005F10385();
        j["token-5D62DC906634BE78EFCB4"] = x.getToken5D62DC906634BE78EFCB4();
        j["token-AA104BAE32C34D8AFA1A2"] = x.getTokenAA104BAE32C34D8AFA1A2();
        j["token-6702818DD29E09D9A22A7"] = x.getToken6702818DD29E09D9A22A7();
        j["token-99BC3D2DE1717F82E2999"] = x.getToken99BC3D2DE1717F82E2999();
        j["token-B3E5E87E867AE2D9B27AC"] = x.getTokenB3E5E87E867AE2D9B27AC();
        j["token-252B7A2AD40FEA145BD85"] = x.getToken252B7A2AD40FEA145BD85();
        j["token-E8FDD64E18F3710D7EE89"] = x.getTokenE8FDD64E18F3710D7EE89();
        j["token-DC53EE2DE0CA847341D8B"] = x.getTokenDC53EE2DE0CA847341D8B();
        j["token-1A7FC9AA0C41A32752294"] = x.getToken1A7FC9AA0C41A32752294();
        j["token-5E258FBC355B5959040BC"] = x.getToken5E258FBC355B5959040BC();
        j["token-0676E8BC26CADB6BAD3AA"] = x.getToken0676E8BC26CADB6BAD3AA();
        j["token-43A0D255D3D202BDEFCB3"] = x.getToken43A0D255D3D202BDEFCB3();
        j["token-2753FA17589D44632BB9F"] = x.getToken2753FA17589D44632BB9F();
        j["token-72D8015C5A42F10EC718C"] = x.getToken72D8015C5A42F10EC718C();
        j["token-537662B35E180A527F7A0"] = x.getToken537662B35E180A527F7A0();
        j["token-E0E410C8AC996EB11CB85"] = x.getTokenE0E410C8AC996EB11CB85();
        j["token-9B1067E1332C4D152B1AD"] = x.getToken9B1067E1332C4D152B1AD();
        j["token-1763F37EE500EF4E84E83"] = x.getToken1763F37EE500EF4E84E83();
        j["token-CD4BEFC7BB8BD00D5A5A9"] = x.getTokenCD4BEFC7BB8BD00D5A5A9();
        j["token-7A458795BD4B0D95651B7"] = x.getToken7A458795BD4B0D95651B7();
        j["token-59C91F284D3472DE5B08D"] = x.getToken59C91F284D3472DE5B08D();
        j["token-2F1CE8C3537D39C3B42A3"] = x.getToken2F1CE8C3537D39C3B42A3();
        j["token-0055D3A7A18B4580C8F8C"] = x.getToken0055D3A7A18B4580C8F8C();
        j["token-E34215A0C5DCD9035DC83"] = x.getTokenE34215A0C5DCD9035DC83();
        j["token-10D15272527BD16B97E84"] = x.getToken10D15272527BD16B97E84();
        j["token-0DE01F3020C5A5A702F9A"] = x.getToken0DE01F3020C5A5A702F9A();
        j["token-9A446B4684FA2B2656ABE"] = x.getToken9A446B4684FA2B2656ABE();
        j["token-CD7E5318FC7C9816CD7B0"] = x.getTokenCD7E5318FC7C9816CD7B0();
        j["token-013C382D3D890D3B1FEA7"] = x.getToken013C382D3D890D3B1FEA7();
        j["token-845B0B9C1B8874A7C2CB6"] = x.getToken845B0B9C1B8874A7C2CB6();
        j["token-B5E715791898691F8D780"] = x.getTokenB5E715791898691F8D780();
        j["token-C159A044375814C6307A2"] = x.getTokenC159A044375814C6307A2();
        j["token-06D8C451D01C967B2A889"] = x.getToken06D8C451D01C967B2A889();
        j["token-4947D300F5746CB9327A9"] = x.getToken4947D300F5746CB9327A9();
        j["token-DBC3DD3DD9962086D98B8"] = x.getTokenDBC3DD3DD9962086D98B8();
        j["token-90B46B4771085F9F64087"] = x.getToken90B46B4771085F9F64087();
        j["token-DA864C7498ED439B5D095"] = x.getTokenDA864C7498ED439B5D095();
        j["token-8EDE4E47E55E8945128AC"] = x.getToken8EDE4E47E55E8945128AC();
        j["token-4F9CEBFCB2BCB7C1F93AE"] = x.getToken4F9CEBFCB2BCB7C1F93AE();
        j["token-C0E5BD48806EA05D8E1B3"] = x.getTokenC0E5BD48806EA05D8E1B3();
        j["token-A713AE88B171CF6DE2584"] = x.getTokenA713AE88B171CF6DE2584();
        j["token-71FE836A3546F7800028F"] = x.getToken71FE836A3546F7800028F();
        j["token-BF85C9CB2643D2241AFBE"] = x.getTokenBF85C9CB2643D2241AFBE();
        j["token-ED59CC7C7EBD1C981D9AD"] = x.getTokenED59CC7C7EBD1C981D9AD();
        j["token-CCF87B3D65FD49EECC6A4"] = x.getTokenCCF87B3D65FD49EECC6A4();
        j["token-238BE16B560DAFB40A8B3"] = x.getToken238BE16B560DAFB40A8B3();
        j["token-88767604C712FA84DE2B4"] = x.getToken88767604C712FA84DE2B4();
        j["token-896C4E49DF74696BBBB8E"] = x.getToken896C4E49DF74696BBBB8E();
        j["token-2884443F1CDB74F7E97A7"] = x.getToken2884443F1CDB74F7E97A7();
        j["token-CD0D1A32B252CB1328B9A"] = x.getTokenCD0D1A32B252CB1328B9A();
        j["token-213D74984AAA195477685"] = x.getToken213D74984AAA195477685();
        j["token-594687C9B2CA65E5CB496"] = x.getToken594687C9B2CA65E5CB496();
        j["token-EC6AA0C48EEA99823E1A2"] = x.getTokenEC6AA0C48EEA99823E1A2();
        j["token-896463C5DE287BB120E80"] = x.getToken896463C5DE287BB120E80();
        j["token-B7B473A156B5AFEF56FA3"] = x.getTokenB7B473A156B5AFEF56FA3();
        j["token-BA252399CE2C5F9194790"] = x.getTokenBA252399CE2C5F9194790();
        j["token-D65725A7C3014B742D999"] = x.getTokenD65725A7C3014B742D999();
        j["token-88AB56442BF560EA449A1"] = x.getToken88AB56442BF560EA449A1();
        j["token-9E6C96FBA7639E73BCE9D"] = x.getToken9E6C96FBA7639E73BCE9D();
        j["token-4201CDF79A2F9160671B3"] = x.getToken4201CDF79A2F9160671B3();
        j["token-868303FF0484A110D1293"] = x.getToken868303FF0484A110D1293();
        j["token-85AD0DE8698EA728E5D9C"] = x.getToken85AD0DE8698EA728E5D9C();
        j["token-FCF78BB01006B90686088"] = x.getTokenFCF78BB01006B90686088();
        j["token-A2BD2B5293660FB1173A6"] = x.getTokenA2BD2B5293660FB1173A6();
        j["token-01D8ECCF9F69D3E9FC7B1"] = x.getToken01D8ECCF9F69D3E9FC7B1();
        j["token-7976D7BDB91692136A1AB"] = x.getToken7976D7BDB91692136A1AB();
        j["token-A86DB4585C3D45CB353AD"] = x.getTokenA86DB4585C3D45CB353AD();
        j["token-71EB4680E8A3A35BA0FB0"] = x.getToken71EB4680E8A3A35BA0FB0();
        j["token-EEAF0DEE6AD40E74DA5BC"] = x.getTokenEEAF0DEE6AD40E74DA5BC();
        j["token-EA6E3BE35693BB6FB8BB7"] = x.getTokenEA6E3BE35693BB6FB8BB7();
        j["token-CEA2074211CEEBD9B5DB3"] = x.getTokenCEA2074211CEEBD9B5DB3();
        j["token-1C733F07F13173D19B29F"] = x.getToken1C733F07F13173D19B29F();
        j["token-20C940B34447AB12CCEA8"] = x.getToken20C940B34447AB12CCEA8();
        j["token-44ABE8B7288C4D59102B5"] = x.getToken44ABE8B7288C4D59102B5();
        j["token-EEC6944070EA265B950B0"] = x.getTokenEEC6944070EA265B950B0();
        j["token-4AFD25AD6666299F2A88B"] = x.getToken4AFD25AD6666299F2A88B();
        j["token-6669C3AABD6369A1AED82"] = x.getToken6669C3AABD6369A1AED82();
        j["token-5B280CB8A69F3D0902EA4"] = x.getToken5B280CB8A69F3D0902EA4();
        j["token-CDFF7828935B02B2CDF86"] = x.getTokenCDFF7828935B02B2CDF86();
        j["token-AF8113E8B8049BAEB73B1"] = x.getTokenAF8113E8B8049BAEB73B1();
        j["token-696B050B75268E575EE84"] = x.getToken696B050B75268E575EE84();
        j["token-892A51A637EF5A550FDBA"] = x.getToken892A51A637EF5A550FDBA();
        j["token-0DE090A2C87A61162BBA4"] = x.getToken0DE090A2C87A61162BBA4();
        j["token-63CC3A387F5BAEF69D4A7"] = x.getToken63CC3A387F5BAEF69D4A7();
        j["token-0B1C3C68043A4F4B61F9F"] = x.getToken0B1C3C68043A4F4B61F9F();
        j["token-0A4486D1E21D43E961BA6"] = x.getToken0A4486D1E21D43E961BA6();
        j["token-5282457FF22ABFDE400B4"] = x.getToken5282457FF22ABFDE400B4();
        j["token-D8774B9492D7CBFC37CB8"] = x.getTokenD8774B9492D7CBFC37CB8();
        j["token-4B5D845A389A0EE19AABF"] = x.getToken4B5D845A389A0EE19AABF();
        j["token-E6D5489CE13AD84D8E7B7"] = x.getTokenE6D5489CE13AD84D8E7B7();
        j["token-9FF026A883F738C0B0CB9"] = x.getToken9FF026A883F738C0B0CB9();
        j["token-CA96E1DBD4F7E72EED48D"] = x.getTokenCA96E1DBD4F7E72EED48D();
        j["token-0D2CB48596748A6B4BFBA"] = x.getToken0D2CB48596748A6B4BFBA();
        j["token-434F3160A979CA1009882"] = x.getToken434F3160A979CA1009882();
        j["token-9220F57D2902D463A1A8D"] = x.getToken9220F57D2902D463A1A8D();
        j["token-096809C9884ED117FB9B6"] = x.getToken096809C9884ED117FB9B6();
        j["token-0189CF14C1ABB9E38D288"] = x.getToken0189CF14C1ABB9E38D288();
        j["token-B044BAAF3986B432AE7BF"] = x.getTokenB044BAAF3986B432AE7BF();
        j["token-B7FA499A68198D093D8A2"] = x.getTokenB7FA499A68198D093D8A2();
        j["token-438FF67AE1F17D825FAB5"] = x.getToken438FF67AE1F17D825FAB5();
        j["token-352D769B1B3BB61DBAFBB"] = x.getToken352D769B1B3BB61DBAFBB();
        j["token-B0F4CB473A8FDBB9CE692"] = x.getTokenB0F4CB473A8FDBB9CE692();
        j["token-CF772D023E3AFAE164899"] = x.getTokenCF772D023E3AFAE164899();
        j["token-EC7A4FC879CE357C2DF84"] = x.getTokenEC7A4FC879CE357C2DF84();
        j["token-089FB68037C80FE98FCAA"] = x.getToken089FB68037C80FE98FCAA();
        j["token-346CF28DB5A65D132898E"] = x.getToken346CF28DB5A65D132898E();
        j["token-DA48586079FD76F4A9FAD"] = x.getTokenDA48586079FD76F4A9FAD();
        j["token-947AF2755679C774793BA"] = x.getToken947AF2755679C774793BA();
        j["token-F07D4E665D02F4187439E"] = x.getTokenF07D4E665D02F4187439E();
        j["token-9E429B12B9261F6A8A489"] = x.getToken9E429B12B9261F6A8A489();
        j["token-E87D96060B9E2D539DC9B"] = x.getTokenE87D96060B9E2D539DC9B();
        j["token-0FA39B41B19A62959098F"] = x.getToken0FA39B41B19A62959098F();
        j["token-1803E0AC70A0D57BBA981"] = x.getToken1803E0AC70A0D57BBA981();
        j["token-48A9BB431CC7D43FD5BA8"] = x.getToken48A9BB431CC7D43FD5BA8();
        j["token-D8AC4F4104AD455C85A84"] = x.getTokenD8AC4F4104AD455C85A84();
        j["token-BF1DEF94AAFC697A6F9BA"] = x.getTokenBF1DEF94AAFC697A6F9BA();
        j["token-7D08480AD0B453BE029A8"] = x.getToken7D08480AD0B453BE029A8();
        j["token-4473A490C2ECEA90DAAB2"] = x.getToken4473A490C2ECEA90DAAB2();
        j["token-B17711FF64A6F6F06299D"] = x.getTokenB17711FF64A6F6F06299D();
        j["token-844BFDA4BE916BD54A3AA"] = x.getToken844BFDA4BE916BD54A3AA();
        j["token-23229682C74347EEB8886"] = x.getToken23229682C74347EEB8886();
        j["token-60E6C57473CB0C88A3E86"] = x.getToken60E6C57473CB0C88A3E86();
        j["token-8C31165AE39E790CCD7B8"] = x.getToken8C31165AE39E790CCD7B8();
        j["token-FE355BF81FC13A6A0DDAE"] = x.getTokenFE355BF81FC13A6A0DDAE();
        j["token-CF3855D906085F5BBFB8B"] = x.getTokenCF3855D906085F5BBFB8B();
        j["token-9F00C7C0F02FB6B6BDB80"] = x.getToken9F00C7C0F02FB6B6BDB80();
        j["token-672CC221DCD193EEA0093"] = x.getToken672CC221DCD193EEA0093();
        j["token-682906AC7B7E242CFC883"] = x.getToken682906AC7B7E242CFC883();
        j["token-3D725B01FB7B9FA90E387"] = x.getToken3D725B01FB7B9FA90E387();
        j["token-6A8D9E562B7D9BCC22487"] = x.getToken6A8D9E562B7D9BCC22487();
        j["token-FCFD60AF5972635E239A1"] = x.getTokenFCFD60AF5972635E239A1();
        j["token-44257D2BB1EB83445748B"] = x.getToken44257D2BB1EB83445748B();
        j["token-C081C1B31AD23306729BC"] = x.getTokenC081C1B31AD23306729BC();
        j["token-91EE07D52D132C0291AA9"] = x.getToken91EE07D52D132C0291AA9();
        j["token-463C9F3509B4B3CE21890"] = x.getToken463C9F3509B4B3CE21890();
        j["token-A8AE1C4637E3977ED139C"] = x.getTokenA8AE1C4637E3977ED139C();
        j["token-072340E8F68E6230FB595"] = x.getToken072340E8F68E6230FB595();
        j["token-AFEABC74E014E1FDCA189"] = x.getTokenAFEABC74E014E1FDCA189();
        j["token-8C03099B0BF7559E4CC8B"] = x.getToken8C03099B0BF7559E4CC8B();
        j["token-CAD830A007BF99AE22588"] = x.getTokenCAD830A007BF99AE22588();
        j["token-803EDA85AD6E2152498B9"] = x.getToken803EDA85AD6E2152498B9();
        j["token-261F79B544B15F18D90BC"] = x.getToken261F79B544B15F18D90BC();
        j["token-57FF4186B72441359A28C"] = x.getToken57FF4186B72441359A28C();
        j["token-9636866E27CE8589EBCAF"] = x.getToken9636866E27CE8589EBCAF();
        j["token-0651D7AAA332194B08DBE"] = x.getToken0651D7AAA332194B08DBE();
        j["token-A158381332191727F40AB"] = x.getTokenA158381332191727F40AB();
        j["token-7D115BFFC746C4DE901B1"] = x.getToken7D115BFFC746C4DE901B1();
        j["token-DCEC566E79614AE22F599"] = x.getTokenDCEC566E79614AE22F599();
        j["token-D7ECF91124B8871B9D484"] = x.getTokenD7ECF91124B8871B9D484();
        j["token-97EFEDD8F2A074CEAAE88"] = x.getToken97EFEDD8F2A074CEAAE88();
        j["token-3E9C3D0C2A9A1151B7B88"] = x.getToken3E9C3D0C2A9A1151B7B88();
        j["token-39AC0A81B17950CF2D2B5"] = x.getToken39AC0A81B17950CF2D2B5();
        j["token-AEC432518E3CF5FDE4FB5"] = x.getTokenAEC432518E3CF5FDE4FB5();
        j["token-5A9C312E1F012AE978784"] = x.getToken5A9C312E1F012AE978784();
        j["token-FBD4128927E1E68A54A81"] = x.getTokenFBD4128927E1E68A54A81();
        j["token-910E582093166C1D0DF80"] = x.getToken910E582093166C1D0DF80();
    }

    inline void from_json(const json &j, MLBJson::RecapAway &x) {
        x.setType(j.at("type").get<MLBJson::AwayType>());
        x.setState(j.at("state").get<MLBJson::State>());
        x.setDate(j.at("date").get<std::string>());
        x.setID(j.at("id").get<std::string>());
        x.setHeadline(j.at("headline").get<std::string>());
        x.setSubhead(j.at("subhead").get<std::string>());
        x.setSEOTitle(j.at("seoTitle").get<std::string>());
        x.setSEOKeywords(j.at("seoKeywords").get<std::string>());
        x.setSEODescription(j.at("seoDescription").get<std::string>());
        x.setSlug(j.at("slug").get<std::string>());
        x.setCommenting(j.at("commenting").get<bool>());
        x.setPhoto(j.at("photo").get<MLBJson::Photo>());
        x.setImage(j.at("image").get<MLBJson::Image>());
        x.setTokenData(j.at("tokenData").get<MLBJson::TokenData>());
        x.setBlurb(j.at("blurb").get<std::string>());
        x.setBody(j.at("body").get<std::string>());
        x.setContributor(j.at("contributor").get<MLBJson::AwayContributor>());
        x.setKeywordsDisplay(
            j.at("keywordsDisplay").get<std::vector<MLBJson::Keywords>>());
        x.setKeywordsAll(
            j.at("keywordsAll").get<std::vector<MLBJson::Keywords>>());
        x.setApproval(j.at("approval").get<std::string>());
        x.setCanonical(j.at("canonical").get<std::string>());
        x.setDataURI(j.at("dataURI").get<std::string>());
        x.setPrimaryKeyword(j.at("primaryKeyword").get<MLBJson::GameNotes>());
        x.setMedia(j.at("media").get<MLBJson::GameNotes>());
    }

    inline void to_json(json &j, const MLBJson::RecapAway &x) {
        j = json::object();
        j["type"] = x.getType();
        j["state"] = x.getState();
        j["date"] = x.getDate();
        j["id"] = x.getID();
        j["headline"] = x.getHeadline();
        j["subhead"] = x.getSubhead();
        j["seoTitle"] = x.getSEOTitle();
        j["seoKeywords"] = x.getSEOKeywords();
        j["seoDescription"] = x.getSEODescription();
        j["slug"] = x.getSlug();
        j["commenting"] = x.getCommenting();
        j["photo"] = x.getPhoto();
        j["image"] = x.getImage();
        j["tokenData"] = x.getTokenData();
        j["blurb"] = x.getBlurb();
        j["body"] = x.getBody();
        j["contributor"] = x.getContributor();
        j["keywordsDisplay"] = x.getKeywordsDisplay();
        j["keywordsAll"] = x.getKeywordsAll();
        j["approval"] = x.getApproval();
        j["canonical"] = x.getCanonical();
        j["dataURI"] = x.getDataURI();
        j["primaryKeyword"] = x.getPrimaryKeyword();
        j["media"] = x.getMedia();
    }

    inline void from_json(const json &j, MLBJson::Playback &x) {
        x.setName(j.at("name").get<MLBJson::Name>());
        x.setWidth(j.at("width").get<std::string>());
        x.setHeight(j.at("height").get<std::string>());
        x.setURL(j.at("url").get<std::string>());
    }

    inline void to_json(json &j, const MLBJson::Playback &x) {
        j = json::object();
        j["name"] = x.getName();
        j["width"] = x.getWidth();
        j["height"] = x.getHeight();
        j["url"] = x.getURL();
    }

    inline void from_json(const json &j, MLBJson::MlbMedia &x) {
        x.setType(j.at("type").get<MLBJson::FluffyType>());
        x.setState(j.at("state").get<MLBJson::State>());
        x.setDate(j.at("date").get<MLBJson::DateEnum>());
        x.setID(j.at("id").get<std::string>());
        x.setTopicID(j.at("topic_id").get<std::string>());
        x.setNoIndex(j.at("noIndex").get<bool>());
        x.setMediaPlaybackID(j.at("mediaPlaybackId").get<std::string>());
        x.setTitle(j.at("title").get<std::string>());
        x.setHeadline(j.at("headline").get<std::string>());
        x.setKicker(j.at("kicker").get<std::string>());
        x.setBlurb(j.at("blurb").get<std::string>());
        x.setDescription(j.at("description").get<std::string>());
        x.setSlug(j.at("slug").get<std::string>());
        x.setSEOTitle(j.at("seoTitle").get<std::string>());
        x.setAuthFlow(j.at("authFlow").get<bool>());
        x.setDuration(j.at("duration").get<std::string>());
        x.setLanguage(j.at("language").get<MLBJson::Language>());
        x.setMediaState(j.at("mediaState").get<MLBJson::MediaState>());
        x.setGUID(j.at("guid").get<std::string>());
        x.setImage(j.at("image").get<MLBJson::Image>());
        x.setKeywordsDisplay(
            j.at("keywordsDisplay").get<std::vector<MLBJson::Keywords>>());
        x.setKeywordsAll(
            j.at("keywordsAll").get<std::vector<MLBJson::Keywords>>());
        x.setMediaPlaybackURL(j.at("mediaPlaybackURL").get<std::string>());
        x.setPlaybacks(j.at("playbacks").get<std::vector<MLBJson::Playback>>());
    }

    inline void to_json(json &j, const MLBJson::MlbMedia &x) {
        j = json::object();
        j["type"] = x.getType();
        j["state"] = x.getState();
        j["date"] = x.getDate();
        j["id"] = x.getID();
        j["topic_id"] = x.getTopicID();
        j["noIndex"] = x.getNoIndex();
        j["mediaPlaybackId"] = x.getMediaPlaybackID();
        j["title"] = x.getTitle();
        j["headline"] = x.getHeadline();
        j["kicker"] = x.getKicker();
        j["blurb"] = x.getBlurb();
        j["description"] = x.getDescription();
        j["slug"] = x.getSlug();
        j["seoTitle"] = x.getSEOTitle();
        j["authFlow"] = x.getAuthFlow();
        j["duration"] = x.getDuration();
        j["language"] = x.getLanguage();
        j["mediaState"] = x.getMediaState();
        j["guid"] = x.getGUID();
        j["image"] = x.getImage();
        j["keywordsDisplay"] = x.getKeywordsDisplay();
        j["keywordsAll"] = x.getKeywordsAll();
        j["mediaPlaybackURL"] = x.getMediaPlaybackURL();
        j["playbacks"] = x.getPlaybacks();
    }

    inline void from_json(const json &j, MLBJson::Mlb &x) {
        x.setType(j.at("type").get<MLBJson::AwayType>());
        x.setState(j.at("state").get<MLBJson::State>());
        x.setDate(j.at("date").get<std::string>());
        x.setID(j.at("id").get<std::string>());
        x.setHeadline(j.at("headline").get<std::string>());
        x.setSubhead(j.at("subhead").get<std::string>());
        x.setSEOTitle(j.at("seoTitle").get<std::string>());
        x.setSEOKeywords(j.at("seoKeywords").get<std::string>());
        x.setSEODescription(j.at("seoDescription").get<std::string>());
        x.setSlug(j.at("slug").get<std::string>());
        x.setCommenting(j.at("commenting").get<bool>());
        x.setPhoto(j.at("photo").get<MLBJson::Photo>());
        x.setImage(j.at("image").get<MLBJson::Image>());
        x.setTokenData(j.at("tokenData").get<MLBJson::TokenData>());
        x.setBlurb(j.at("blurb").get<std::string>());
        x.setBody(j.at("body").get<std::string>());
        x.setContributor(j.at("contributor").get<MLBJson::AwayContributor>());
        x.setKeywordsDisplay(
            j.at("keywordsDisplay").get<std::vector<MLBJson::Keywords>>());
        x.setKeywordsAll(
            j.at("keywordsAll").get<std::vector<MLBJson::Keywords>>());
        x.setApproval(j.at("approval").get<std::string>());
        x.setCanonical(j.at("canonical").get<std::string>());
        x.setDataURI(j.at("dataURI").get<std::string>());
        x.setPrimaryKeyword(j.at("primaryKeyword").get<MLBJson::GameNotes>());
        x.setMedia(j.at("media").get<MLBJson::MlbMedia>());
    }

    inline void to_json(json &j, const MLBJson::Mlb &x) {
        j = json::object();
        j["type"] = x.getType();
        j["state"] = x.getState();
        j["date"] = x.getDate();
        j["id"] = x.getID();
        j["headline"] = x.getHeadline();
        j["subhead"] = x.getSubhead();
        j["seoTitle"] = x.getSEOTitle();
        j["seoKeywords"] = x.getSEOKeywords();
        j["seoDescription"] = x.getSEODescription();
        j["slug"] = x.getSlug();
        j["commenting"] = x.getCommenting();
        j["photo"] = x.getPhoto();
        j["image"] = x.getImage();
        j["tokenData"] = x.getTokenData();
        j["blurb"] = x.getBlurb();
        j["body"] = x.getBody();
        j["contributor"] = x.getContributor();
        j["keywordsDisplay"] = x.getKeywordsDisplay();
        j["keywordsAll"] = x.getKeywordsAll();
        j["approval"] = x.getApproval();
        j["canonical"] = x.getCanonical();
        j["dataURI"] = x.getDataURI();
        j["primaryKeyword"] = x.getPrimaryKeyword();
        j["media"] = x.getMedia();
    }

    inline void from_json(const json &j, MLBJson::Recap &x) {
        x.setHome(j.at("home").get<MLBJson::RecapAway>());
        x.setAway(j.at("away").get<MLBJson::RecapAway>());
        x.setMlb(j.at("mlb").get<MLBJson::Mlb>());
    }

    inline void to_json(json &j, const MLBJson::Recap &x) {
        j = json::object();
        j["home"] = x.getHome();
        j["away"] = x.getAway();
        j["mlb"] = x.getMlb();
    }

    inline void from_json(const json &j, MLBJson::Editorial &x) {
        x.setRecap(j.at("recap").get<MLBJson::Recap>());
    }

    inline void to_json(json &j, const MLBJson::Editorial &x) {
        j = json::object();
        j["recap"] = x.getRecap();
    }

    inline void from_json(const json &j, MLBJson::ContentMedia &x) {
        x.setFreeGame(j.at("freeGame").get<bool>());
        x.setEnhancedGame(j.at("enhancedGame").get<bool>());
    }

    inline void to_json(json &j, const MLBJson::ContentMedia &x) {
        j = json::object();
        j["freeGame"] = x.getFreeGame();
        j["enhancedGame"] = x.getEnhancedGame();
    }

    inline void from_json(const json &j, MLBJson::Content &x) {
        x.setLink(j.at("link").get<std::string>());
        x.setEditorial(j.at("editorial").get<MLBJson::Editorial>());
        x.setMedia(j.at("media").get<MLBJson::ContentMedia>());
        x.setHighlights(j.at("highlights").get<MLBJson::GameNotes>());
        x.setSummary(j.at("summary").get<MLBJson::GameNotes>());
        x.setGameNotes(j.at("gameNotes").get<MLBJson::GameNotes>());
    }

    inline void to_json(json &j, const MLBJson::Content &x) {
        j = json::object();
        j["link"] = x.getLink();
        j["editorial"] = x.getEditorial();
        j["media"] = x.getMedia();
        j["highlights"] = x.getHighlights();
        j["summary"] = x.getSummary();
        j["gameNotes"] = x.getGameNotes();
    }

    inline void from_json(const json &j, MLBJson::Loser &x) {
        x.setID(j.at("id").get<int64_t>());
        x.setFullName(j.at("fullName").get<std::string>());
        x.setLink(j.at("link").get<std::string>());
    }

    inline void to_json(json &j, const MLBJson::Loser &x) {
        j = json::object();
        j["id"] = x.getID();
        j["fullName"] = x.getFullName();
        j["link"] = x.getLink();
    }

    inline void from_json(const json &j, MLBJson::Decisions &x) {
        x.setWinner(j.at("winner").get<MLBJson::Loser>());
        x.setLoser(j.at("loser").get<MLBJson::Loser>());
        x.setSave(MLBJson::get_optional<MLBJson::Loser>(j, "save"));
    }

    inline void to_json(json &j, const MLBJson::Decisions &x) {
        j = json::object();
        j["winner"] = x.getWinner();
        j["loser"] = x.getLoser();
        j["save"] = x.getSave();
    }

    inline void from_json(const json &j, MLBJson::Status &x) {
        x.setAbstractGameState(
            j.at("abstractGameState").get<MLBJson::AbstractGameStateEnum>());
        x.setCodedGameState(
            j.at("codedGameState").get<MLBJson::AbstractGameCode>());
        x.setDetailedState(
            j.at("detailedState").get<MLBJson::AbstractGameStateEnum>());
        x.setStatusCode(j.at("statusCode").get<MLBJson::AbstractGameCode>());
        x.setAbstractGameCode(
            j.at("abstractGameCode").get<MLBJson::AbstractGameCode>());
    }

    inline void to_json(json &j, const MLBJson::Status &x) {
        j = json::object();
        j["abstractGameState"] = x.getAbstractGameState();
        j["codedGameState"] = x.getCodedGameState();
        j["detailedState"] = x.getDetailedState();
        j["statusCode"] = x.getStatusCode();
        j["abstractGameCode"] = x.getAbstractGameCode();
    }

    inline void from_json(const json &j, MLBJson::LeagueRecord &x) {
        x.setWINS(j.at("wins").get<int64_t>());
        x.setLosses(j.at("losses").get<int64_t>());
        x.setPct(j.at("pct").get<std::string>());
    }

    inline void to_json(json &j, const MLBJson::LeagueRecord &x) {
        j = json::object();
        j["wins"] = x.getWINS();
        j["losses"] = x.getLosses();
        j["pct"] = x.getPct();
    }

    inline void from_json(const json &j, MLBJson::Venue &x) {
        x.setID(j.at("id").get<int64_t>());
        x.setName(j.at("name").get<std::string>());
        x.setLink(j.at("link").get<std::string>());
    }

    inline void to_json(json &j, const MLBJson::Venue &x) {
        j = json::object();
        j["id"] = x.getID();
        j["name"] = x.getName();
        j["link"] = x.getLink();
    }

    inline void from_json(const json &j, MLBJson::TeamsAway &x) {
        x.setLeagueRecord(j.at("leagueRecord").get<MLBJson::LeagueRecord>());
        x.setScore(j.at("score").get<int64_t>());
        x.setTeam(j.at("team").get<MLBJson::Venue>());
        x.setIsWinner(j.at("isWinner").get<bool>());
        x.setSplitSquad(j.at("splitSquad").get<bool>());
        x.setSeriesNumber(j.at("seriesNumber").get<int64_t>());
    }

    inline void to_json(json &j, const MLBJson::TeamsAway &x) {
        j = json::object();
        j["leagueRecord"] = x.getLeagueRecord();
        j["score"] = x.getScore();
        j["team"] = x.getTeam();
        j["isWinner"] = x.getIsWinner();
        j["splitSquad"] = x.getSplitSquad();
        j["seriesNumber"] = x.getSeriesNumber();
    }

    inline void from_json(const json &j, MLBJson::Teams &x) {
        x.setAway(j.at("away").get<MLBJson::TeamsAway>());
        x.setHome(j.at("home").get<MLBJson::TeamsAway>());
    }

    inline void to_json(json &j, const MLBJson::Teams &x) {
        j = json::object();
        j["away"] = x.getAway();
        j["home"] = x.getHome();
    }

    inline void from_json(const json &j, MLBJson::Game &x) {
        x.setGamePk(j.at("gamePk").get<int64_t>());
        x.setLink(j.at("link").get<std::string>());
        x.setGameType(j.at("gameType").get<MLBJson::GameType>());
        x.setSeason(j.at("season").get<std::string>());
        x.setGameDate(j.at("gameDate").get<std::string>());
        x.setStatus(j.at("status").get<MLBJson::Status>());
        x.setTeams(j.at("teams").get<MLBJson::Teams>());
        x.setDecisions(j.at("decisions").get<MLBJson::Decisions>());
        x.setVenue(j.at("venue").get<MLBJson::Venue>());
        x.setContent(j.at("content").get<MLBJson::Content>());
        x.setIsTie(j.at("isTie").get<bool>());
        x.setGameNumber(j.at("gameNumber").get<int64_t>());
        x.setPublicFacing(j.at("publicFacing").get<bool>());
        x.setDoubleHeader(j.at("doubleHeader").get<MLBJson::DoubleHeader>());
        x.setGamedayType(j.at("gamedayType").get<MLBJson::GamedayType>());
        x.setTiebreaker(j.at("tiebreaker").get<MLBJson::DoubleHeader>());
        x.setCalendarEventID(j.at("calendarEventID").get<std::string>());
        x.setSeasonDisplay(j.at("seasonDisplay").get<std::string>());
        x.setDayNight(j.at("dayNight").get<MLBJson::DayNight>());
        x.setScheduledInnings(j.at("scheduledInnings").get<int64_t>());
        x.setInningBreakLength(j.at("inningBreakLength").get<int64_t>());
        x.setGamesInSeries(j.at("gamesInSeries").get<int64_t>());
        x.setSeriesGameNumber(j.at("seriesGameNumber").get<int64_t>());
        x.setSeriesDescription(
            j.at("seriesDescription").get<MLBJson::SeriesDescription>());
        x.setRecordSource(j.at("recordSource").get<MLBJson::RecordSource>());
        x.setIfNecessary(j.at("ifNecessary").get<MLBJson::DoubleHeader>());
        x.setIfNecessaryDescription(
            j.at("ifNecessaryDescription")
                .get<MLBJson::IfNecessaryDescription>());
    }

    inline void to_json(json &j, const MLBJson::Game &x) {
        j = json::object();
        j["gamePk"] = x.getGamePk();
        j["link"] = x.getLink();
        j["gameType"] = x.getGameType();
        j["season"] = x.getSeason();
        j["gameDate"] = x.getGameDate();
        j["status"] = x.getStatus();
        j["teams"] = x.getTeams();
        j["decisions"] = x.getDecisions();
        j["venue"] = x.getVenue();
        j["content"] = x.getContent();
        j["isTie"] = x.getIsTie();
        j["gameNumber"] = x.getGameNumber();
        j["publicFacing"] = x.getPublicFacing();
        j["doubleHeader"] = x.getDoubleHeader();
        j["gamedayType"] = x.getGamedayType();
        j["tiebreaker"] = x.getTiebreaker();
        j["calendarEventID"] = x.getCalendarEventID();
        j["seasonDisplay"] = x.getSeasonDisplay();
        j["dayNight"] = x.getDayNight();
        j["scheduledInnings"] = x.getScheduledInnings();
        j["inningBreakLength"] = x.getInningBreakLength();
        j["gamesInSeries"] = x.getGamesInSeries();
        j["seriesGameNumber"] = x.getSeriesGameNumber();
        j["seriesDescription"] = x.getSeriesDescription();
        j["recordSource"] = x.getRecordSource();
        j["ifNecessary"] = x.getIfNecessary();
        j["ifNecessaryDescription"] = x.getIfNecessaryDescription();
    }

    inline void from_json(const json &j, MLBJson::DateElement &x) {
        x.setDate(j.at("date").get<std::string>());
        x.setTotalItems(j.at("totalItems").get<int64_t>());
        x.setTotalEvents(j.at("totalEvents").get<int64_t>());
        x.setTotalGames(j.at("totalGames").get<int64_t>());
        x.setTotalGamesInProgress(j.at("totalGamesInProgress").get<int64_t>());
        x.setGames(j.at("games").get<std::vector<MLBJson::Game>>());
        x.setEvents(j.at("events").get<std::vector<json>>());
    }

    inline void to_json(json &j, const MLBJson::DateElement &x) {
        j = json::object();
        j["date"] = x.getDate();
        j["totalItems"] = x.getTotalItems();
        j["totalEvents"] = x.getTotalEvents();
        j["totalGames"] = x.getTotalGames();
        j["totalGamesInProgress"] = x.getTotalGamesInProgress();
        j["games"] = x.getGames();
        j["events"] = x.getEvents();
    }

    inline void from_json(const json &j, MLBJson::Dss &x) {
        x.setCopyright(j.at("copyright").get<std::string>());
        x.setTotalItems(j.at("totalItems").get<int64_t>());
        x.setTotalEvents(j.at("totalEvents").get<int64_t>());
        x.setTotalGames(j.at("totalGames").get<int64_t>());
        x.setTotalGamesInProgress(j.at("totalGamesInProgress").get<int64_t>());
        x.setDates(j.at("dates").get<std::vector<MLBJson::DateElement>>());
    }

    inline void to_json(json &j, const MLBJson::Dss &x) {
        j = json::object();
        j["copyright"] = x.getCopyright();
        j["totalItems"] = x.getTotalItems();
        j["totalEvents"] = x.getTotalEvents();
        j["totalGames"] = x.getTotalGames();
        j["totalGamesInProgress"] = x.getTotalGamesInProgress();
        j["dates"] = x.getDates();
    }

    inline void from_json(const json &j, MLBJson::Source &x) {
        if (j == "MLB.com")
            x = MLBJson::Source::MLB_COM;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::Source &x) {
            switch (x) {
            case MLBJson::Source::MLB_COM:
                j = "MLB.com";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::AspectRatio &x) {
        if (j == "")
            x = MLBJson::AspectRatio::EMPTY;
        else if (j == "16:9")
            x = MLBJson::AspectRatio::THE_169;
        else if (j == "4:3")
            x = MLBJson::AspectRatio::THE_43;
        else if (j == "5:2")
            x = MLBJson::AspectRatio::THE_52;
        else if (j == "64:27")
            x = MLBJson::AspectRatio::THE_6427;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::AspectRatio &x) {
            switch (x) {
            case MLBJson::AspectRatio::EMPTY:
                j = "";
                break;
            case MLBJson::AspectRatio::THE_169:
                j = "16:9";
                break;
            case MLBJson::AspectRatio::THE_43:
                j = "4:3";
                break;
            case MLBJson::AspectRatio::THE_52:
                j = "5:2";
                break;
            case MLBJson::AspectRatio::THE_6427:
                j = "64:27";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::TypeEnum &x) {
        if (j == "active_beatwriters")
            x = MLBJson::TypeEnum::ACTIVE_BEATWRITERS;
        else if (j == "active_columnists")
            x = MLBJson::TypeEnum::ACTIVE_COLUMNISTS;
        else if (j == "all_star")
            x = MLBJson::TypeEnum::ALL_STAR;
        else if (j == "archive-element")
            x = MLBJson::TypeEnum::ARCHIVE_ELEMENT;
        else if (j == "authflow")
            x = MLBJson::TypeEnum::AUTHFLOW;
        else if (j == "away_team_id")
            x = MLBJson::TypeEnum::AWAY_TEAM_ID;
        else if (j == "bodyParagraphCount")
            x = MLBJson::TypeEnum::BODY_PARAGRAPH_COUNT;
        else if (j == "bodyWordCount")
            x = MLBJson::TypeEnum::BODY_WORD_COUNT;
        else if (j == "calendar_event_id")
            x = MLBJson::TypeEnum::CALENDAR_EVENT_ID;
        else if (j == "cbssports_player_id")
            x = MLBJson::TypeEnum::CBSSPORTS_PLAYER_ID;
        else if (j == "clob_autoTagSkip_playerCards")
            x = MLBJson::TypeEnum::CLOB_AUTO_TAG_SKIP_PLAYER_CARDS;
        else if (j == "closed_captions_location_ttml")
            x = MLBJson::TypeEnum::CLOSED_CAPTIONS_LOCATION_TTML;
        else if (j == "closed_captions_location_vtt")
            x = MLBJson::TypeEnum::CLOSED_CAPTIONS_LOCATION_VTT;
        else if (j == "combined_media_state")
            x = MLBJson::TypeEnum::COMBINED_MEDIA_STATE;
        else if (j == "content")
            x = MLBJson::TypeEnum::CONTENT;
        else if (j == "event_date")
            x = MLBJson::TypeEnum::EVENT_DATE;
        else if (j == "game_events_location_plist")
            x = MLBJson::TypeEnum::GAME_EVENTS_LOCATION_PLIST;
        else if (j == "game_id")
            x = MLBJson::TypeEnum::GAME_ID;
        else if (j == "game_pk")
            x = MLBJson::TypeEnum::GAME_PK;
        else if (j == "home_team_id")
            x = MLBJson::TypeEnum::HOME_TEAM_ID;
        else if (j == "inning_index_location_plist")
            x = MLBJson::TypeEnum::INNING_INDEX_LOCATION_PLIST;
        else if (j == "inning_index_location_xml")
            x = MLBJson::TypeEnum::INNING_INDEX_LOCATION_XML;
        else if (j == "language")
            x = MLBJson::TypeEnum::LANGUAGE;
        else if (j == "mlbtax")
            x = MLBJson::TypeEnum::MLBTAX;
        else if (j == "mmtax")
            x = MLBJson::TypeEnum::MMTAX;
        else if (j == "player_id")
            x = MLBJson::TypeEnum::PLAYER_ID;
        else if (j == "run_scoring_plays_location_plist")
            x = MLBJson::TypeEnum::RUN_SCORING_PLAYS_LOCATION_PLIST;
        else if (j == "subject")
            x = MLBJson::TypeEnum::SUBJECT;
        else if (j == "sv_id")
            x = MLBJson::TypeEnum::SV_ID;
        else if (j == "team_file_code")
            x = MLBJson::TypeEnum::TEAM_FILE_CODE;
        else if (j == "team_id")
            x = MLBJson::TypeEnum::TEAM_ID;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::TypeEnum &x) {
            switch (x) {
            case MLBJson::TypeEnum::ACTIVE_BEATWRITERS:
                j = "active_beatwriters";
                break;
            case MLBJson::TypeEnum::ACTIVE_COLUMNISTS:
                j = "active_columnists";
                break;
            case MLBJson::TypeEnum::ALL_STAR:
                j = "all_star";
                break;
            case MLBJson::TypeEnum::ARCHIVE_ELEMENT:
                j = "archive-element";
                break;
            case MLBJson::TypeEnum::AUTHFLOW:
                j = "authflow";
                break;
            case MLBJson::TypeEnum::AWAY_TEAM_ID:
                j = "away_team_id";
                break;
            case MLBJson::TypeEnum::BODY_PARAGRAPH_COUNT:
                j = "bodyParagraphCount";
                break;
            case MLBJson::TypeEnum::BODY_WORD_COUNT:
                j = "bodyWordCount";
                break;
            case MLBJson::TypeEnum::CALENDAR_EVENT_ID:
                j = "calendar_event_id";
                break;
            case MLBJson::TypeEnum::CBSSPORTS_PLAYER_ID:
                j = "cbssports_player_id";
                break;
            case MLBJson::TypeEnum::CLOB_AUTO_TAG_SKIP_PLAYER_CARDS:
                j = "clob_autoTagSkip_playerCards";
                break;
            case MLBJson::TypeEnum::CLOSED_CAPTIONS_LOCATION_TTML:
                j = "closed_captions_location_ttml";
                break;
            case MLBJson::TypeEnum::CLOSED_CAPTIONS_LOCATION_VTT:
                j = "closed_captions_location_vtt";
                break;
            case MLBJson::TypeEnum::COMBINED_MEDIA_STATE:
                j = "combined_media_state";
                break;
            case MLBJson::TypeEnum::CONTENT:
                j = "content";
                break;
            case MLBJson::TypeEnum::EVENT_DATE:
                j = "event_date";
                break;
            case MLBJson::TypeEnum::GAME_EVENTS_LOCATION_PLIST:
                j = "game_events_location_plist";
                break;
            case MLBJson::TypeEnum::GAME_ID:
                j = "game_id";
                break;
            case MLBJson::TypeEnum::GAME_PK:
                j = "game_pk";
                break;
            case MLBJson::TypeEnum::HOME_TEAM_ID:
                j = "home_team_id";
                break;
            case MLBJson::TypeEnum::INNING_INDEX_LOCATION_PLIST:
                j = "inning_index_location_plist";
                break;
            case MLBJson::TypeEnum::INNING_INDEX_LOCATION_XML:
                j = "inning_index_location_xml";
                break;
            case MLBJson::TypeEnum::LANGUAGE:
                j = "language";
                break;
            case MLBJson::TypeEnum::MLBTAX:
                j = "mlbtax";
                break;
            case MLBJson::TypeEnum::MMTAX:
                j = "mmtax";
                break;
            case MLBJson::TypeEnum::PLAYER_ID:
                j = "player_id";
                break;
            case MLBJson::TypeEnum::RUN_SCORING_PLAYS_LOCATION_PLIST:
                j = "run_scoring_plays_location_plist";
                break;
            case MLBJson::TypeEnum::SUBJECT:
                j = "subject";
                break;
            case MLBJson::TypeEnum::SV_ID:
                j = "sv_id";
                break;
            case MLBJson::TypeEnum::TEAM_FILE_CODE:
                j = "team_file_code";
                break;
            case MLBJson::TypeEnum::TEAM_ID:
                j = "team_id";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::State &x) {
        if (j == "A")
            x = MLBJson::State::A;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::State &x) {
            switch (x) {
            case MLBJson::State::A:
                j = "A";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::PurpleType &x) {
        if (j == "playerCard")
            x = MLBJson::PurpleType::PLAYER_CARD;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::PurpleType &x) {
            switch (x) {
            case MLBJson::PurpleType::PLAYER_CARD:
                j = "playerCard";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::DateEnum &x) {
        if (j == "2018-06-10T13:05:00-0400")
            x = MLBJson::DateEnum::THE_20180610_T13_05000400;
        else if (j == "2018-06-10T13:07:00-0400")
            x = MLBJson::DateEnum::THE_20180610_T13_07000400;
        else if (j == "2018-06-10T13:10:00-0400")
            x = MLBJson::DateEnum::THE_20180610_T13_10000400;
        else if (j == "2018-06-10T13:35:00-0400")
            x = MLBJson::DateEnum::THE_20180610_T13_35000400;
        else if (j == "2018-06-10T14:10:00-0400")
            x = MLBJson::DateEnum::THE_20180610_T14_10000400;
        else if (j == "2018-06-10T14:20:00-0400")
            x = MLBJson::DateEnum::THE_20180610_T14_20000400;
        else if (j == "2018-06-10T15:05:00-0400")
            x = MLBJson::DateEnum::THE_20180610_T15_05000400;
        else if (j == "2018-06-10T15:10:00-0400")
            x = MLBJson::DateEnum::THE_20180610_T15_10000400;
        else if (j == "2018-06-10T16:05:00-0400")
            x = MLBJson::DateEnum::THE_20180610_T16_05000400;
        else if (j == "2018-06-10T16:10:00-0400")
            x = MLBJson::DateEnum::THE_20180610_T16_10000400;
        else if (j == "2018-06-10T20:05:00-0400")
            x = MLBJson::DateEnum::THE_20180610_T20_05000400;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::DateEnum &x) {
            switch (x) {
            case MLBJson::DateEnum::THE_20180610_T13_05000400:
                j = "2018-06-10T13:05:00-0400";
                break;
            case MLBJson::DateEnum::THE_20180610_T13_07000400:
                j = "2018-06-10T13:07:00-0400";
                break;
            case MLBJson::DateEnum::THE_20180610_T13_10000400:
                j = "2018-06-10T13:10:00-0400";
                break;
            case MLBJson::DateEnum::THE_20180610_T13_35000400:
                j = "2018-06-10T13:35:00-0400";
                break;
            case MLBJson::DateEnum::THE_20180610_T14_10000400:
                j = "2018-06-10T14:10:00-0400";
                break;
            case MLBJson::DateEnum::THE_20180610_T14_20000400:
                j = "2018-06-10T14:20:00-0400";
                break;
            case MLBJson::DateEnum::THE_20180610_T15_05000400:
                j = "2018-06-10T15:05:00-0400";
                break;
            case MLBJson::DateEnum::THE_20180610_T15_10000400:
                j = "2018-06-10T15:10:00-0400";
                break;
            case MLBJson::DateEnum::THE_20180610_T16_05000400:
                j = "2018-06-10T16:05:00-0400";
                break;
            case MLBJson::DateEnum::THE_20180610_T16_10000400:
                j = "2018-06-10T16:10:00-0400";
                break;
            case MLBJson::DateEnum::THE_20180610_T20_05000400:
                j = "2018-06-10T20:05:00-0400";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::FluffyType &x) {
        if (j == "video")
            x = MLBJson::FluffyType::VIDEO;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::FluffyType &x) {
            switch (x) {
            case MLBJson::FluffyType::VIDEO:
                j = "video";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::TentacledType &x) {
        if (j == "hyperLink")
            x = MLBJson::TentacledType::HYPER_LINK;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::TentacledType &x) {
            switch (x) {
            case MLBJson::TentacledType::HYPER_LINK:
                j = "hyperLink";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::AwayType &x) {
        if (j == "article")
            x = MLBJson::AwayType::ARTICLE;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::AwayType &x) {
            switch (x) {
            case MLBJson::AwayType::ARTICLE:
                j = "article";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::Language &x) {
        if (j == "en")
            x = MLBJson::Language::EN;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::Language &x) {
            switch (x) {
            case MLBJson::Language::EN:
                j = "en";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::MediaState &x) {
        if (j == "MEDIA_ARCHIVE")
            x = MLBJson::MediaState::MEDIA_ARCHIVE;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::MediaState &x) {
            switch (x) {
            case MLBJson::MediaState::MEDIA_ARCHIVE:
                j = "MEDIA_ARCHIVE";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::Name &x) {
        if (j == "FLASH_1200K_640X360")
            x = MLBJson::Name::FLASH_1200_K_640_X360;
        else if (j == "FLASH_1800K_960X540")
            x = MLBJson::Name::FLASH_1800_K_960_X540;
        else if (j == "FLASH_2500K_1280X720")
            x = MLBJson::Name::FLASH_2500_K_1280_X720;
        else if (j == "FLASH_450K_400X224")
            x = MLBJson::Name::FLASH_450_K_400_X224;
        else if (j == "HTTP_CLOUD_ANDROID_TABLET")
            x = MLBJson::Name::HTTP_CLOUD_ANDROID_TABLET;
        else if (j == "HTTP_CLOUD_MOBILE")
            x = MLBJson::Name::HTTP_CLOUD_MOBILE;
        else if (j == "HTTP_CLOUD_TABLET")
            x = MLBJson::Name::HTTP_CLOUD_TABLET;
        else if (j == "HTTP_CLOUD_TABLET_60")
            x = MLBJson::Name::HTTP_CLOUD_TABLET_60;
        else if (j == "HTTP_CLOUD_WIRED")
            x = MLBJson::Name::HTTP_CLOUD_WIRED;
        else if (j == "HTTP_CLOUD_WIRED_60")
            x = MLBJson::Name::HTTP_CLOUD_WIRED_60;
        else if (j == "HTTP_CLOUD_WIRED_WEB")
            x = MLBJson::Name::HTTP_CLOUD_WIRED_WEB;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::Name &x) {
            switch (x) {
            case MLBJson::Name::FLASH_1200_K_640_X360:
                j = "FLASH_1200K_640X360";
                break;
            case MLBJson::Name::FLASH_1800_K_960_X540:
                j = "FLASH_1800K_960X540";
                break;
            case MLBJson::Name::FLASH_2500_K_1280_X720:
                j = "FLASH_2500K_1280X720";
                break;
            case MLBJson::Name::FLASH_450_K_400_X224:
                j = "FLASH_450K_400X224";
                break;
            case MLBJson::Name::HTTP_CLOUD_ANDROID_TABLET:
                j = "HTTP_CLOUD_ANDROID_TABLET";
                break;
            case MLBJson::Name::HTTP_CLOUD_MOBILE:
                j = "HTTP_CLOUD_MOBILE";
                break;
            case MLBJson::Name::HTTP_CLOUD_TABLET:
                j = "HTTP_CLOUD_TABLET";
                break;
            case MLBJson::Name::HTTP_CLOUD_TABLET_60:
                j = "HTTP_CLOUD_TABLET_60";
                break;
            case MLBJson::Name::HTTP_CLOUD_WIRED:
                j = "HTTP_CLOUD_WIRED";
                break;
            case MLBJson::Name::HTTP_CLOUD_WIRED_60:
                j = "HTTP_CLOUD_WIRED_60";
                break;
            case MLBJson::Name::HTTP_CLOUD_WIRED_WEB:
                j = "HTTP_CLOUD_WIRED_WEB";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::DayNight &x) {
        if (j == "day")
            x = MLBJson::DayNight::DAY;
        else if (j == "night")
            x = MLBJson::DayNight::NIGHT;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::DayNight &x) {
            switch (x) {
            case MLBJson::DayNight::DAY:
                j = "day";
                break;
            case MLBJson::DayNight::NIGHT:
                j = "night";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::DoubleHeader &x) {
        if (j == "N")
            x = MLBJson::DoubleHeader::N;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::DoubleHeader &x) {
            switch (x) {
            case MLBJson::DoubleHeader::N:
                j = "N";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::GameType &x) {
        if (j == "R")
            x = MLBJson::GameType::R;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::GameType &x) {
            switch (x) {
            case MLBJson::GameType::R:
                j = "R";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::GamedayType &x) {
        if (j == "P")
            x = MLBJson::GamedayType::P;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::GamedayType &x) {
            switch (x) {
            case MLBJson::GamedayType::P:
                j = "P";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::IfNecessaryDescription &x) {
        if (j == "Normal Game")
            x = MLBJson::IfNecessaryDescription::NORMAL_GAME;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::IfNecessaryDescription &x) {
            switch (x) {
            case MLBJson::IfNecessaryDescription::NORMAL_GAME:
                j = "Normal Game";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::RecordSource &x) {
        if (j == "S")
            x = MLBJson::RecordSource::S;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::RecordSource &x) {
            switch (x) {
            case MLBJson::RecordSource::S:
                j = "S";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::SeriesDescription &x) {
        if (j == "Regular Season")
            x = MLBJson::SeriesDescription::REGULAR_SEASON;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::SeriesDescription &x) {
            switch (x) {
            case MLBJson::SeriesDescription::REGULAR_SEASON:
                j = "Regular Season";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::AbstractGameCode &x) {
        if (j == "F")
            x = MLBJson::AbstractGameCode::F;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::AbstractGameCode &x) {
            switch (x) {
            case MLBJson::AbstractGameCode::F:
                j = "F";
                break;
            default:
                throw "This should not happen";
            }
    }

    inline void from_json(const json &j, MLBJson::AbstractGameStateEnum &x) {
        if (j == "Final")
            x = MLBJson::AbstractGameStateEnum::FINAL;
        else
            throw "Input JSON does not conform to schema";
    }

    inline void to_json(json &j, const MLBJson::AbstractGameStateEnum &x) {
            switch (x) {
            case MLBJson::AbstractGameStateEnum::FINAL:
                j = "Final";
                break;
            default:
                throw "This should not happen";
            }
    }
} // namespace nlohmann

#endif /* DSSModel_h */
