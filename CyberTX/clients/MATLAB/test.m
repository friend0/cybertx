numChannels = 6;
ctx = CyberTX("COM3", 38400, numChannels);
ctx
ppmValues = zeros(1,numChannels,'uint16');
for i=1:numChannels
    ppmValues(i) = 1000 + 1000/16 * (i-1);
end
ctx.writePPM(ppmValues)
ctx.delete()