
namespace usecase{

    int pin = 2;
    char msg[50];
    int value = 0;
    String exp_topic = "command";
    String exp_command = "trigger";

    void loadConfig(String topicConfig, String commandConfig, String triggerPinConfig){
        exp_topic = topicConfig;
        exp_command = commandConfig;
        pin = triggerPinConfig.toInt();
        Serial.println("Loading Config, topis is " + exp_topic +", command: "+exp_command+ ", Pin is " + String(pin));
    }

    void callback(char* topic, String message) {
        Serial.print("Message arrived on topic: ");
        Serial.print(topic);
        Serial.print(". Message: ");

        if (String(topic) == exp_topic) {
             
            if (message==exp_command){
                Serial.println("Switch!");
                digitalWrite(pin, HIGH);
                delay(500);
                digitalWrite(pin, LOW);
            }

        }
    }
}
