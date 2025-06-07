#include "sensor.h"

sensor** init_sensors(){
    static sensor* sensors[NUM_SENSORS];
    for(int i = 0; i < NUM_SENSORS; i++){
        int choice = generate_rand_number(0.0, NUM_SENSORS);
        
        sensors[i] = malloc(sizeof(sensor));
        sensors[i]->topic = get_sensor_topic(choice);
        sensors[i]->data_value = 0;
        // Change the way how we can recognize the min and max for the sensors
        if(choice == 0){ // Temperature sensor
            sensors[i]->limit_min = 15.0;
            sensors[i]->limit_max = 30.0;
        } else { // Humidity sensor
            sensors[i]->limit_min = 0.3;
            sensors[i]->limit_max = 0.7;

        }
    }
    
    return sensors;
}

int send_data(sensor* data){
    printf("%s sensor is connected to gateway socket\n", data->topic);
    printf("%s sensor sending %f...\n", data->topic ,data->data_value);
    return 0;
}

char *get_sensor_topic(int sensor_type){
    static const char *sensor_types[] = {"Temperature", "Humidity"};
    static const char *topics[] = {"Kitchen", "Living Room", "Bedroom", "Bathroom", "Garage"};

    int len_topics = sizeof(topics) / sizeof(topics[0]);

    int topic_choice = generate_rand_number(0, len_topics - 1);
    int size_malloc = strlen(ROOT_LEVEL) + strlen(sensor_types[sensor_type]) + strlen(topics[topic_choice]) + 3 ; // +3 for space and null terminator
    
    char *sensor_topic = malloc(size_malloc);
    if(sensor_topic == NULL){
        fprintf(stderr, "Memory allocation failed for sensor topic\n");
        exit(EXIT_FAILURE);
    }
    
    snprintf(sensor_topic, size_malloc, "%s/%s/%s", ROOT_LEVEL, topics[topic_choice], sensor_types[sensor_type]);
    return sensor_topic;
}

void* start_simulation(void* arg){
    sensor* sensor_data = (sensor*) arg; 
    
    printf("Starting Simulation of %s Sensor...\n", sensor_data->topic);
    while(1){
        sensor_data->data_value = generate_rand_number(sensor_data->limit_min, sensor_data->limit_max);
        send_data(sensor_data);  
        printf("\n");
        sleep(1);
    }
    return NULL;
}