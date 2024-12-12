import React, { useState, useEffect } from 'react';
import { View, Text, TextInput, Button, ActivityIndicator } from 'react-native';
import axios from 'axios';
import {Icon as MaterialCommunityIcons} from '@expo/vector-icons';

const WeatherUpdates = () => {
  const [searchQuery, setSearchQuery] = useState('Jaipur'); // Default city
  const [weatherData, setWeatherData] = useState(null);
  const [loading, setLoading] = useState(false);

  useEffect(() => {
    if (searchQuery) {
      fetchWeatherData(searchQuery);
    }
  }, []);

  const fetchWeatherData = (cityName) => {
    setLoading(true);
    const apiKey = 'YOUR_API_KEY';
    const weatherUrl = `https://api.openweathermap.org/data/2.5/weather?q=${cityName}&appid=${apiKey}&units=metric`;

    axios.get(weatherUrl)
      .then(response => {
        setWeatherData(response.data);
        setLoading(false);
      })
      .catch(error => {
        console.log('Error fetching weather data:', error);
        setLoading(false);
      });
  };

  const handleSearch = () => {
    fetchWeatherData(searchQuery);
  };

  const iconColors = {
    Clear: '#ffb300',      // Sunny yellow
    Clouds: '#90a4ae',     // Cloudy gray
    Rain: '#4fc3f7',       // Rainy blue
    Thunderstorm: '#f44336',
    Drizzle: '#64b5f6',
    Snow: '#81d4fa',
    Mist: '#b0bec5',
  };
  
  const iconColor = iconColors[weatherCondition] || '#ffb300'; // Default sunny color
  
  // Use the color in the Icon component
  <Icon name={iconName} size={100} color={iconColor} />

  const weatherIcons = {
    Clear: 'weather-sunny',
    Clouds: 'weather-cloudy',
    Rain: 'weather-rainy',
    Thunderstorm: 'weather-lightning',
    Drizzle: 'weather-partly-rainy',
    Snow: 'weather-snowy',
    Mist: 'weather-fog',
    Smoke: 'weather-fog',
    Haze: 'weather-hazy',
    Dust: 'weather-fog',
    Fog: 'weather-fog',
    Sand: 'weather-fog',
    Ash: 'weather-fog',
    Squall: 'weather-windy',
    Tornado: 'weather-tornado',
    Night: 'weather-night',
    'Partly Cloudy': 'weather-partly-cloudy',
    'Cloudy Alert': 'weather-cloudy-alert',
    'Heavy Snow': 'weather-snowy-heavy',
    'Snowy Rainy': 'weather-snowy-rainy',
    'Sunny Alert': 'weather-sunny-alert',
    Hurricane: 'weather-hurricane',
    'Lightning Rainy': 'weather-lightning-rainy',
    'Partly Snowy': 'weather-partly-snowy',
    'Partly Lightning': 'weather-partly-lightning',
    'Partly Cloudy Night': 'weather-night-partly-cloudy',
    'Pouring Rain': 'weather-pouring',
  };
  

  return (
    <View style={{ padding: 20 }}>
      <TextInput
        style={{ borderColor: 'gray', borderWidth: 1, padding: 10, marginBottom: 10 }}
        placeholder="Enter city name"
        value={searchQuery}
        onChangeText={setSearchQuery}
      />
      <Button title="Search" onPress={handleSearch} />
      
      {loading ? (
        <ActivityIndicator size="large" color="#0000ff" />
      ) : weatherData ? (
        <View style={{ alignItems: 'center', marginTop: 20 }}>
          <Text style={{ fontSize: 24, fontWeight: 'bold' }}>{weatherData.name}</Text>
          <Icon name="weather-sunny" size={100} color="#ffb300" /> {/* Dynamic icon can be set based on conditions */}
          <Text style={{ fontSize: 18 }}>Temperature: {weatherData.main.temp}°C</Text>
          <Text>Weather: {weatherData.weather[0].description}</Text>
          <Text>Humidity: {weatherData.main.humidity}%</Text>
          <Text>Wind Speed: {weatherData.wind.speed} m/s</Text>
        </View>
      ) : (
        <Text>No data available.</Text>
      )}
    </View>
  );
};

export default WeatherUpdates;
