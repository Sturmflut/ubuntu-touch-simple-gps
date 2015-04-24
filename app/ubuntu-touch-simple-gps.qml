import QtQuick 2.0
import Ubuntu.Components 1.1
import Simplegps 1.0

/*!
    \brief MainView with Tabs element.
           First Tab has a single Label and
           second Tab has a single ToolbarAction.
*/

MainView {
    // objectName for functional testing purposes (autopilot-qt5)
    objectName: "mainView"

    // Note! applicationName needs to match the "name" field of the click manifest
    applicationName: "ubuntu-touch-simple-gps.sturmflut"

    /*
     This property enables the application to change orientation
     when the device is rotated. The default is false.
    */
    //automaticOrientation: true

    // Removes the old toolbar and enables new features of the new header.
    useDeprecatedToolbar: false

    width: units.gu(35)
    height: units.gu(76)

    Page {
        title: i18n.tr("Simple GPS")

        GPSDataProvider {
            id: gpsDataProvider

            interval: 1
        }


        GPSLocationView {
            id: satelliteLocationView

            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right

            width: parent.width
            height: width

            gpsDataProvider: gpsDataProvider
        }


        GPSSNRView {
            id: satelliteSNRView

            width: parent.width
            height: units.gu(7)

            anchors.top: satelliteLocationView.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            gpsDataProvider: gpsDataProvider
        }
    }
}

