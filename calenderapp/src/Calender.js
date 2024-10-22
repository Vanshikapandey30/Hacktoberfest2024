import React, { useState, useEffect } from 'react';
import { View, Text, StyleSheet, Dimensions, ActivityIndicator, Alert, SafeAreaView, Modal, TouchableOpacity } from 'react-native';
import CustomDropdown from './components/CustomDropdown';
import { Image } from 'expo-image';
import NetInfo from '@react-native-community/netinfo';
import { GestureHandlerRootView, GestureDetector, Gesture } from 'react-native-gesture-handler';
import Animated, { useSharedValue, useAnimatedStyle, withSpring, withDecay } from 'react-native-reanimated';

const CalendarApp = () => {
  const currentYear = new Date().getFullYear();
  const currentMonth = new Date().getMonth() + 1;

  const [selectedYear, setSelectedYear] = useState(currentYear);
  const [selectedMonth, setSelectedMonth] = useState(currentMonth);
  const [finalImageUrl, setFinalImageUrl] = useState('');
  const [quote, setQuote] = useState('');
  const [loadingQuote, setLoadingQuote] = useState(true);
  const [isConnected, setIsConnected] = useState(true); 
  const [urlError, setUrlError] = useState(false); 
  const [loadingImage, setLoadingImage] = useState(true); 
  const [isModalVisible, setIsModalVisible] = useState(false); // Modal state

  const screenWidth = Dimensions.get('window').width;
  const screenHeight = Dimensions.get('window').height;
  const placeholderImage = 'https://via.placeholder.com/400';

  // Pinch-to-zoom shared values
  const scale = useSharedValue(1);
  const translationX = useSharedValue(0);
  const translationY = useSharedValue(0);

  // Pan gesture handler to move the image after zooming
  const panGesture = Gesture.Pan()
    .onUpdate((event) => {
      translationX.value = event.translationX;
      translationY.value = event.translationY;
    })
    .onEnd((event) => {
      // Decay to add a smooth transition after releasing the pan
      translationX.value = withDecay({ velocity: event.velocityX });
      translationY.value = withDecay({ velocity: event.velocityY });
    });

  // Pinch gesture handler for zooming
  const pinchGesture = Gesture.Pinch()
    .onUpdate((event) => {
      scale.value = event.scale;
    })
    .onEnd(() => {
      // No need for event here, just reset scale to 1
      scale.value = withSpring(1);  // Reset zoom after the pinch ends
    });


  // Combining both pinch and pan gestures
  const composedGesture = Gesture.Simultaneous(pinchGesture, panGesture);

  // Animated style for image scaling and translation
  const animatedStyle = useAnimatedStyle(() => {
    const adjustedScale = Math.max(scale.value, 1);  // Prevent scaling below 1

    return {
      transform: [
        { scale: adjustedScale },
        { translateX: translationX.value },
        { translateY: translationY.value }
      ],
    };
  });

  const generateYears = () => {
    const years = [];
    const pastYears = 5;
    for (let i = currentYear; i >= currentYear - pastYears; i--) {
      years.push({ label: `${i}`, value: i });
    }
    return years;
  };

  const months = [
    { label: 'January', value: 1 },
    { label: 'February', value: 2 },
    { label: 'March', value: 3 },
    { label: 'April', value: 4 },
    { label: 'May', value: 5 },
    { label: 'June', value: 6 },
    { label: 'July', value: 7 },
    { label: 'August', value: 8 },
    { label: 'September', value: 9 },
    { label: 'October', value: 10 },
    { label: 'November', value: 11 },
    { label: 'December', value: 12 },
  ];

  useEffect(() => {
    const unsubscribe = NetInfo.addEventListener(state => {
      setIsConnected(state.isConnected);
    });
    return () => {
      unsubscribe(); 
    };
  }, []);

  useEffect(() => {
    const initialUrl = getImageUrl(currentYear, currentMonth);
    setFinalImageUrl(initialUrl);
    fetchRandomQuote();
  }, []);

  const getImageUrl = (year, month) => {
    const formattedMonth = month < 10 ? `0${month}` : month;
    return `https://rajsmsa.nic.in/images/cal/${year}${formattedMonth}.jpg`;
  };

  const fetchRandomQuote = async () => {
    try {
      const response = await fetch('https://zenquotes.io/api/random');
      const data = await response.json();
      if (data && data.length > 0) {
        setQuote(data[0].q + " - " + data[0].a);
      }
    } catch (error) {
      setQuote('Failed to fetch quote');
    } finally {
      setLoadingQuote(false);
    }
  };

  useEffect(() => {
    const newUrl = getImageUrl(selectedYear, selectedMonth);
    setFinalImageUrl(newUrl);
    setUrlError(false);
    setLoadingImage(true); 
  }, [selectedYear, selectedMonth]);

  const handleImageLoad = () => {
    setLoadingImage(false);
  };

  const handleImageError = () => {
    setUrlError(true);
    setLoadingImage(false); 
  };

  const toggleModal = () => {
    setIsModalVisible(!isModalVisible);
  };

  return (
    <SafeAreaView style={styles.container}>
      <Text style={styles.header}>Rajasthan Government Holiday Calendar</Text>
      <View style={styles.quoteContainer}>
        {loadingQuote ? (
          <ActivityIndicator size="large" color="#0000ff" />
        ) : (
          <Text style={styles.quoteText}>{quote}</Text>
        )}
      </View>
      {!isConnected && (
        <View style={styles.errorContainer}>
          <Text style={styles.errorText}>No internet connection. Please check your connection.</Text>
        </View>
      )}

      <View style={styles.dropdownRow} >
        <View  style={styles.dropdown}>
          <CustomDropdown
            items={generateYears()}
            selectedValue={selectedYear}
            onValueChange={setSelectedYear}
            placeholder="Select Year"
          />
        </View>
        <View  style={styles.dropdown}>
          <CustomDropdown
            items={months}
            selectedValue={selectedMonth}
            onValueChange={setSelectedMonth}
            placeholder="Select Month"
          />
        </View>
      </View>

      <View style={styles.imageContainer}>
        {loadingImage && <ActivityIndicator size="large" color="#0000ff" />}
        <TouchableOpacity onPress={toggleModal}> 
          <Image
            source={{ uri: !urlError ? finalImageUrl : placeholderImage }}
            contentFit="contain"
            cachePolicy="none"
            style={{
              width: screenWidth - 10,  
              height: screenHeight * 0.8, 
            }}
            onLoad={handleImageLoad} 
            onError={handleImageError} 
          />  
        </TouchableOpacity>
      </View>

      {/* Modal for enlarged image with pinch-to-zoom and panning */}
      <Modal visible={isModalVisible} transparent={true} animationType="fade">
        <GestureHandlerRootView style={styles.modalContainer}>
          <GestureDetector gesture={composedGesture}>
            <Animated.View style={animatedStyle}>
              <Image
                source={{ uri: !urlError ? finalImageUrl : placeholderImage }}
                contentFit="contain"
                style={{
                  width: screenWidth - 10,
                  height: screenHeight * 0.9,
                }}
              />
            </Animated.View>
          </GestureDetector>
          <TouchableOpacity style={styles.modalCloseButton} onPress={toggleModal}>
            <Text style={styles.modalCloseText}>Close</Text>
          </TouchableOpacity>
        </GestureHandlerRootView>
      </Modal>
    </SafeAreaView>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: 30,
    backgroundColor: '#e0f7fa',
  },
  header: {
    fontSize: 26,
    fontWeight: 'bold',
    textAlign: 'center',
    marginBottom: 20,
    color: '#004d40', 
  },
  dropdownRow: {
    flexDirection: 'row',
    justifyContent: 'center',
    marginBottom: 20,
  },
  dropdown: {
    width: '45%',
    marginHorizontal: 5,
    borderRadius: 10, 
  },
   quoteContainer: {
    marginBottom: 15,
    paddingHorizontal: 15,
    paddingVertical: 10,
    marginHorizontal: 10,
    backgroundColor: '#ffffff',
    borderRadius: 10, 
    justifyContent: 'center',
    alignItems: 'center',
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.3,
    shadowRadius: 3,
    elevation: 5,
  },
  quoteText: {
    fontSize: 14, 
    fontStyle: 'italic',
    textAlign: 'center',
    color: '#00796b', 
    fontFamily: 'serif', 
  },
  imageContainer: {
        flex: 1,
    borderTopLeftRadius: 40,
    borderTopRightRadius: 40,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: "#ffffff",
    overflow: 'hidden',
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.8,
    shadowRadius: 3,
    elevation: 5, 
  },
  errorContainer: {
    padding: 10,
    backgroundColor: '#ffdddd',
    borderRadius: 5,
    marginVertical: 10,
  },
  errorText: {
    color: '#d8000c',
    textAlign: 'center',
  },
  modalContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: 'rgba(0, 0, 0, 0.8)',
  },
  modalCloseButton: {
    position: 'absolute',
    top: 40,
    right: 20,
    padding: 10,
    backgroundColor: '#ff4d4d',
    borderRadius: 5,
    zIndex: 999999,
  },
  modalCloseText: {
    color: '#fff',
    fontWeight: 'bold',
    fontSize: 16,
  },
});

export default CalendarApp;
