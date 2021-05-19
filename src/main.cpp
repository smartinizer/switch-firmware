#include <Smartinizer.h>
#include <usecase.hh>

Smartinizer* sm;

void setup() {
  
  sm = new Smartinizer();
  sm->setup();
  usecase::loadConfig(sm->getConfigByKey("topic"),sm->getConfigByKey("command"), sm->getConfigByKey("trigger_pin"));
  pinMode(usecase::pin, OUTPUT);
  sm->register_usecase(usecase::callback);
}


void loop() {
  sm->loop();
}
