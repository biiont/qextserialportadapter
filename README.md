# qextserialportadapter

QSerialPort library use QScopedPointer extensively. This class was introduced at version 4.6 of Qt.

As some of my projects should compile on Qt 4.4.2 the only option available for me is to use QextSerialPort. But I decided to make adapter classes which would mimic use of QtSerialPort API using QextSerialPort as backend.

Only some parts of API are adapted as this library is at work in progress state.
