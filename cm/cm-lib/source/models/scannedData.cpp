#include "scannedData.hpp"
#include "../controllers/LowLevelFunctionality/DeviceController/DeviceController.hpp"
namespace ac {
namespace models {
////INTEGRAL PARTS OF CLASS
ScannedData::ScannedData(QObject *parent) : Entity(parent, "ScannedData")
{
    name = static_cast<cm::data::StringDecorator*>(addDataItem(new cm::data::StringDecorator(this, "recentlyScannedData", "dataInfo")));
    fileName = "ABCD";
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

////CHART value
QLineSeries* ScannedData::get_ui_profile() const
{
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
//    update_ui_profile();

//    emit profile_changed();
}

void ScannedData::update_ui_profile(){
    convertedProfile->clear();
    for(auto pair: profileData){
        convertedProfile->append(pair.first,pair.second);
    }
    printProfile();
    emit profile_changed();
}

////CHART value
QString  ScannedData::get_ui_result()
{
    return QString::fromStdString(ac::translators::getResultName(finalResult));
}

QString ScannedData::get_ui_filename()
{
    return QString::fromStdString(fileName);
}

////debugging
void ScannedData::printProfile(){
    qDebug()<<"Printing Profile, profile size:"<<profileData.size();
    for(auto pair: profileData){
        qDebug()<<"x: "<<pair.first<<", y: "<<pair.second;
    }
}



}
}
