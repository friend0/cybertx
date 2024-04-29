classdef CyberTX < handle
    properties
        routing_bits
        numChannels
        port
    end
    
    methods
        function obj = CyberTX(port, baud)
            obj.numChannels = 16;
            obj.routing_bits = log2(obj.numChannels);
            obj.port = serialport(port, baud);
        end
        
        function writePPM(obj, ppmValues)
            write(obj.port, 0x01, 'uint8');
            write(obj.port, 0x02, 'uint8');
            write(obj.port, 0x03, 'uint8');     %indicate start of frame (0b1111111111111111)
            
            for i=1:obj.numChannels
                %should probably check if ppmValues are greater than the 11-bit number
                %we are expecting, with a range of 2047
                
                route = cast(i-1, 'uint16'); % cast channel to 16 bits
                route = bitshift(route, 16-obj.routing_bits); % shift the routing bits into the most significant bits of route
                
                LSB = bitand(ppmValues(i), 0x00FF);
                MSB = bitand(ppmValues(i), 0x0F00);
                
                MSB = bitor(MSB, route);        %add routing bits to the  MSB data
                MSB = cast(bitshift(MSB, -8), 'uint8');
                LSB = cast(LSB, 'uint8');
                
                i
                dec2bin(MSB, 8)
                dec2bin(LSB, 8)
                
                write(obj.port, MSB, 'uint8');
                write(obj.port, LSB, 'uint8');
                write(obj.port, 0x15, 'uint8');
            end
            write(obj.port, 0x15, 'uint8')
            write(obj.port, 0x12, 'uint8')
        end
        
        function delete(obj)
            delete(obj.port);
        end
    end
end



% delete(obj.port)
% obj.port = serialport("COM3", 38400);
% obj.port.flush()
% configureTerminator(obj.port);



% Packet is 4 bits of routing data supporting 16 channels of ppm, with 11
% bits of data allowing values between 0 and 2047
% rrrr0ddddddddddd

% frame_length = 16;
% numChannels = 16;
% routing_bits = log2(numChannels);
% ppmValues = zeros(1,numChannels,'uint16');

% for i=1:numChannels
%     ppmValues(i) = 1000 + 1000/16 * (i-1);
% end

% write(obj.port, 0x01, 'uint8');
% write(obj.port, 0x02, 'uint8');
% write(obj.port, 0x03, 'uint8');     %indicate start of frame (0b1111111111111111)

% for i=1:numChannels
%     %should probably check if ppmValues are greater than the 11-bit number
%     %we are expecting, with a range of 2047

%     route = cast(i-1, 'uint16'); % cast channel to 16 bits
%     route = bitshift(route, 16-routing_bits); % shift the routing bits into the most significant bits of route

%     LSB = bitand(ppmValues(i), 0x00FF);
%     MSB = bitand(ppmValues(i), 0x0F00);

%     MSB = bitor(MSB, route);        %add routing bits to the  MSB data
%     MSB = cast(bitshift(MSB, -8), 'uint8');
%     LSB = cast(LSB, 'uint8');

%     i
%     dec2bin(MSB, 8)
%     dec2bin(LSB, 8)

%     write(obj.port, MSB, 'uint8');
%     write(obj.port, LSB, 'uint8');
%     write(obj.port, 0x15, 'uint8');
% end

% write(obj.port, 0x15, 'uint8')
% write(obj.port, 0x12, 'uint8')
% delete(obj.port)
