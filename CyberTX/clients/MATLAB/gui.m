function simpleGUI

    ctx = CyberTX('COM3', 38400, 1, 4);

    % Create the main figure
    hFig = figure('Position', [100, 100, 425, 350], 'MenuBar', 'none', 'Name', 'Simple GUI', 'NumberTitle', 'off', 'Resize', 'off');
    
    % Create four sliders with corresponding labels
    aileronSlider = uicontrol('Style', 'slider', 'Min', 1000, 'Max', 2000, 'Value', 1500, 'Position', [50, 280, 300, 20], 'Callback', @(src, event) commonCallback(src, event, ctx));
    elevatorSlider = uicontrol('Style', 'slider', 'Min', 1000, 'Max', 2000, 'Value', 1500, 'Position', [50, 240, 300, 20], 'Callback', @(src, event) commonCallback(src, event, ctx));
    throttleSlider = uicontrol('Style', 'slider', 'Min', 1000, 'Max', 2000, 'Value', 1000, 'Position', [50, 200, 300, 20], 'Callback', @(src, event) commonCallback(src, event, ctx));
    rudderSlider = uicontrol('Style', 'slider', 'Min', 1000, 'Max', 2000, 'Value', 1500, 'Position', [50, 160, 300, 20], 'Callback', @(src, event) commonCallback(src, event, ctx));
    
    uicontrol('Style', 'text', 'Position', [10, 280, 40, 20], 'String', 'Aileron');
    uicontrol('Style', 'text', 'Position', [10, 240, 40, 20], 'String', 'Elevator');
    uicontrol('Style', 'text', 'Position', [10, 200, 40, 20], 'String', 'Throttle');
    uicontrol('Style', 'text', 'Position', [10, 160, 40, 20], 'String', 'Rudder');

    % Create two switches with corresponding labels
    armSwitch = uicontrol('Style', 'checkbox', 'String', 'Arm', 'Position', [100, 120, 100, 30], 'Callback', @(src, event) commonCallback(src, event, ctx));
    modeSwitch = uicontrol('Style', 'checkbox', 'String', 'Mode', 'Position', [250, 120, 100, 30], 'Callback', @(src, event) commonCallback(src, event, ctx));

    % Create text labels to show the slider values
    aileronLabel = uicontrol('Style', 'text', 'Position', [360, 280, 50, 20], 'String', num2str(get(aileronSlider, 'Value')));
    elevatorLabel = uicontrol('Style', 'text', 'Position', [360, 240, 50, 20], 'String', num2str(get(elevatorSlider, 'Value')));
    throttleLabel = uicontrol('Style', 'text', 'Position', [360, 200, 50, 20], 'String', num2str(get(throttleSlider, 'Value')));
    rudderLabel = uicontrol('Style', 'text', 'Position', [360, 160, 50, 20], 'String', num2str(get(rudderSlider, 'Value')));
    
    % Store handles for easy access in the callback
    handles.aileronSlider = aileronSlider;
    handles.elevatorSlider = elevatorSlider;
    handles.throttleSlider = throttleSlider;
    handles.rudderSlider = rudderSlider;
    handles.armSwitch = armSwitch;
    handles.modeSwitch = modeSwitch;
    handles.aileronLabel = aileronLabel;
    handles.elevatorLabel = elevatorLabel;
    handles.throttleLabel = throttleLabel;
    handles.rudderLabel = rudderLabel;
    
    % Store handles in the figure's UserData property
    set(hFig, 'UserData', handles);
end


% Common callback function to handle updates for all UI components
function commonCallback(src, event, ctx)
        % Get the figure handle
        hFig = ancestor(src, 'figure');
        
        % Retrieve handles from the figure's UserData property
        handles = get(hFig, 'UserData');
        
        % Update slider labels
        set(handles.aileronLabel, 'String', num2str(get(handles.aileronSlider, 'Value')));
        set(handles.elevatorLabel, 'String', num2str(get(handles.elevatorSlider, 'Value')));
        set(handles.throttleLabel, 'String', num2str(get(handles.throttleSlider, 'Value')));
        set(handles.rudderLabel, 'String', num2str(get(handles.rudderSlider, 'Value')));
        
        command = struct('Aileron', get(handles.aileronSlider, 'Value'), ...
            'Elevator', get(handles.elevatorSlider, 'Value'), ...
            'Throttle', get(handles.throttleSlider, 'Value'), ...
            'Rudder', get(handles.rudderSlider, 'Value'), ...
            'Arm', 1000, ...
            'Mode', 1000);
      
        % Check switch states and display messages
        if get(handles.armSwitch, 'Value')
            disp('Arm is ON');
            command.Arm = 2000;
        else
            disp('Arm is OFF');
            command.Arm = 1000;
        end
        
        if get(handles.modeSwitch, 'Value')
            disp('Mode is ON');
            command.Mode = 2000;
        else
            disp('Mode is OFF');
            command.Mode = 1000;
        end
        ctx.writePPM([command.Aileron, command.Elevator, command.Throttle, command.Rudder])
        % ctx.writePPM([command.Aileron, command.Elevator, command.Throttle, command.Rudder, command.Arm, command.Mode])
end
simpleGUI()
% delete ctx
% clear all
% close all