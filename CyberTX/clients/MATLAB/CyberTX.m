classdef CyberTX < handle
    properties
        routing_bits
        port
        baud_rate
        line
        num_channels
    end
    
    methods
        % allow configurable number of channels
        function obj = CyberTX(port, baud_rate, line, num_channels)
            if nargin < 3
                line = 1; % Default line
            end
            if nargin < 4
                num_channels = 8; % Default channels
            end
            obj.port = serialport(port, baud_rate);
            obj.line = line;
            obj.num_channels = num_channels;
            obj.routing_bits = ceil(log2(obj.num_channels));
        end
        
        function writePPM(obj, ppmValues)
            write(obj.port, 0x01, 'uint8');
            write(obj.port, 0x02, 'uint8');
            dec2hex(obj.num_channels, 2)
            write(obj.port, 0x04, 'uint8');     %indicate start of frame (0b1111111111111111)
            
            for i=1:obj.num_channels
                %should probably check if ppmValues are greater than the 11-bit number
                % we are expecting, with a range of 2047p
                route = cast(i-1, 'uint16'); % cast channel to 16 bits
                route = bitshift(route, 16-obj.routing_bits); % shift the routing bits into the most significant bits of route
                LSB = bitand(ppmValues(i), 0x00FF);
                MSB = bitand(ppmValues(i), 0x0F00);
                
                MSB = bitor(MSB, route);        %add routing bits to the  MSB data
                MSB = cast(bitshift(MSB, -8), 'uint8');
                LSB = cast(LSB, 'uint8');

                write(obj.port, MSB, 'uint8');
                write(obj.port, LSB, 'uint8');
                write(obj.port, 0xDD, 'uint8');
            end
            write(obj.port, 0xD4, 'uint8')
        end
        
        function delete(obj)
            delete(obj.port);
        end
    end
end