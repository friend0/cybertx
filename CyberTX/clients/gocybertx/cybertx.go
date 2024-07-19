package gocybertx

import (
	"github.com/pkg/errors"
	"github.com/tarm/serial"
	"google.golang.org/protobuf/proto"
)

type CybertxClient struct {
	conn *serial.Port
}

func NewCybertxClient(port string, baudrate int) (*CybertxClient, error) {
	serialport, err := serial.OpenPort(&serial.Config{
		Name: port,     // Replace with your serial port name
		Baud: baudrate, // Set the baud rate
	})
	if err != nil {
		return nil, errors.Wrap(err, "failed to open serial port")
	}
	return &CybertxClient{
		conn: serialport,
	}, nil
}

func (c *CybertxClient) UpdateLine(line, channel, channelValue int32) error {
	updateLine := &UpdateLine{
		Line:         line,
		Channel:      channel,
		ChannelValue: channelValue,
	}
	data, err := proto.Marshal(updateLine)
	if err != nil {
		return errors.Wrap(err, "failed to encode update line")
	}
	c.conn.Write(data)
	return nil
}

func (c *CybertxClient) UpdateAllLines(line int32, channelValues []int32) error {
	updateAll := &UpdateAll{
		Line:          line,
		ChannelValues: channelValues,
	}
	data, err := proto.Marshal(updateAll)
	if err != nil {
		return errors.Wrap(err, "failed to encode update all lines")
	}
	c.conn.Write(data)
	return nil
}

func (c *CybertxClient) Close() {
	c.conn.Close()
}
