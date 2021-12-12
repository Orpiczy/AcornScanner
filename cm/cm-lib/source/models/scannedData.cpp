#include "scannedData.hpp"

ScannedData::ScannedData(QObject *parent) : Entity(parent, "ScannedData")
{
    /*
     *
     *
     *  IMPLEMENTATION - PARSING TO JSON
     *
     *
     */
}

ScannedData::ScannedData(QObject *parent, const QJsonObject &json): ScannedData(parent)
{
    update(json);
}

QLineSeries* ScannedData::get_ui_profile() const
{
    //   convertedProfile = {};
    //   for(auto pair: profileData){
    //       convertedProfile->append(pair.first,pair.second);
    //   }

    return convertedProfile;
}

void ScannedData::set_ui_profile(QLineSeries *ui_profile)
{
    if(convertedProfile == ui_profile) {
        return;
    }
    if(convertedProfile)
    {
        if(convertedProfile->parent() == this) // is owner
        {
            delete convertedProfile;
        }

    }
    convertedProfile = ui_profile;
    emit profile_changed();
}

