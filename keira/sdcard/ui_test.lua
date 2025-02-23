local keyboard_test = keyboardUI("SAY MY NAME") 
keyboard_test:setValue("TEST")
while true do      
    keyboard_test:update()  
    keyboard_test:draw()      
    if keyboard_test:isFinished() then
        break
    end
end


local alert_test = alertUI("YOU ARE?", keyboard_test:getValue()) 
while true do      
    alert_test:update()  
    alert_test:draw()      
    if alert_test:isFinished() then
        break
    end
end

alert_test:setTitle("NO!!! YOU ARE:")
alert_test:setMessage("BEST IN THE WORLD")

while true do      
    alert_test:update()  
    alert_test:draw()      
    if alert_test:isFinished() then
        break
    end
end

local alert_test = alertUI("DO YOU WANNA PLAY", "[A]YES\n[B]NO") 
alert_test:addActivationButton("a")
alert_test:addActivationButton("b")
alert_test:draw()      
while true do   
    alert_test:update()     
    if alert_test:isFinished() then
        break
    end
end

which_key = alert_test:getButton()

if which_key == "a" then
    alert_test:setTitle("ALRIGHT")
    alert_test:setMessage("LET`S PLAY")
elseif which_key == "b" then
    alert_test:setTitle("Okay")
    alert_test:setMessage(":(")
end

alert_test:draw()      
while true do   
    alert_test:update()     
    if alert_test:isFinished() then
        break
    end
end

local alert_test = progressUI("ROCKET", "launch") 
for i = 0, 100 do
    display.fill_screen(0)

    alert_test:setProgress(i)
    alert_test:draw()
    util.sleep(0.05)
end