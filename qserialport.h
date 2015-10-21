#ifndef QSERIALPORT_H
#define QSERIALPORT

#include <qextserialport.h>

QT_BEGIN_NAMESPACE

class QSerialPort : public QextSerialPort {
public:
    static const BaudRateType Baud19200;

    static const DataBitsType Data8;

    static const ParityType NoParity;

    static const StopBitsType OneStop;

    static const FlowType NoFlowControl;

#define QEXT_ERROR_BASE 1000
    static const ulong QextErrorBase;

    enum SerialPortError {
        NoError = QEXT_ERROR_BASE + E_NO_ERROR,
        DeviceNotFoundError = QEXT_ERROR_BASE + E_FILE_NOT_FOUND,
        PermissionError = QEXT_ERROR_BASE + E_PERMISSION_DENIED,
        OpenError = 3,
        NotOpenError = 13,
        ParityError = QEXT_ERROR_BASE + E_RECEIVE_PARITY_ERROR,
        FramingError = QEXT_ERROR_BASE + E_FRAMING_ERROR,
        BreakConditionError = QEXT_ERROR_BASE + E_BREAK_CONDITION,
        WriteError = QEXT_ERROR_BASE + E_WRITE_FAILED,
        ReadError = QEXT_ERROR_BASE + E_READ_FAILED,
        ResourceError = 9,
        UnsupportedOperationError = 10,
        TimeoutError = 12,
        UnknownError = 11
    };

    /*
        OpenError = 3,
        NotOpenError = 13,
        ResourceError = 9,
        UnsupportedOperationError = 10,
        TimeoutError = 12,
        UnknownError = 11
     */
    const SerialPortError error()
    {
        const ulong err = lastError();
        switch(err) {
        case E_INVALID_FD:
            qDebug("Invalid file descriptor (port was not opened correctly). Translated from errno EBADF or ENOTTY.");
        case E_CAUGHT_NON_BLOCKED_SIGNAL:
            qDebug("Caught a non-blocked signal (POSIX). Translated from errno EINTR.");
        case E_PORT_TIMEOUT:
            qDebug("Operation timed out (POSIX).");
        case E_INVALID_DEVICE:
            qDebug("The file opened by the port is not a valid device.");
        case E_IO_ERROR:
            qDebug("There was an I/O error while communicating with the port.");
        case E_BUFFER_OVERRUN:
            qDebug("Character buffer overrun.");
        case E_TRANSMIT_OVERFLOW:
            qDebug("Transmit buffer overflow.");
        case E_NO_MEMORY:
            qDebug("Unable to allocate memory tables (POSIX). Translated from errno ENOMEM.");
        case E_AGAIN:
            qDebug("Device is already locked. Translated from errno EAGAIN.");
            return UnknownError;
        default:
            //case E_NO_ERROR: // No Error has occurred
            //case E_READ_FAILED: // General read operation failure
            //case E_WRITE_FAILED: // General write operation failure
            //case E_FILE_NOT_FOUND: // The %1 file doesn't exists
            //case E_PERMISSION_DENIED: // Permission denied; errno: EACCESS
            //case E_RECEIVE_OVERFLOW: // Receive buffer overflow
            //case E_RECEIVE_PARITY_ERROR: // The port detected a parity error in the received data
            //case E_FRAMING_ERROR: // The port detected a framing error (usually caused by incorrect baud rate settings)
            //case E_BREAK_CONDITION: // The port detected a break condition
            return static_cast<SerialPortError>(err);
        }
    }
};

const BaudRateType QSerialPort::Baud19200 = Baud19200;

const DataBitsType QSerialPort::Data8 = DATA_8;

const ParityType QSerialPort::NoParity = PAR_NONE;

const StopBitsType QSerialPort::OneStop = STOP_1;

const FlowType QSerialPort::NoFlowControl = FLOW_OFF;

const ulong QSerialPort::QextErrorBase = QEXT_ERROR_BASE;

QT_END_NAMESPACE

#endif // QSERIALPORT_H
