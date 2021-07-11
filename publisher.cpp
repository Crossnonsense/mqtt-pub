#include <stdio.h>
#include <mosquitto.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


int main(){
	int rc;
	struct mosquitto * mosq;

	json msg;
	
	msg["x"] = 150;
	msg["y"] = 100;
	msg["width"] = 60;
	msg["height"] = 30;	
	
	mosquitto_lib_init();

	mosq = mosquitto_new("publisher-test", true, NULL);

	rc = mosquitto_connect(mosq, "localhost", 1884, 60);
	if(rc != 0){
		printf("Client could not connect to broker! Error Code: %d\n", rc);
		mosquitto_destroy(mosq);
		return -1;
	}
	printf("We are now connected to the broker!\n");

	mosquitto_publish(mosq, NULL, "test/t1", sizeof(msg), &msg, 0, false);

	mosquitto_disconnect(mosq);
	mosquitto_destroy(mosq);

	mosquitto_lib_cleanup();
	return 0;
}
