// CustomDropdown.js
import React from 'react';
import { View, Text, TouchableOpacity, StyleSheet, Modal, FlatList } from 'react-native';
import {Ionicons} from '@expo/vector-icons';
const CustomDropdown = ({ items, selectedValue, onValueChange, placeholder }) => {
  const [modalVisible, setModalVisible] = React.useState(false);

  const selectedItem = items.find(item => item.value === selectedValue);

  return (
    <View style={styles.container}>
      <TouchableOpacity
        style={styles.dropdown}
        onPress={() => setModalVisible(true)}
        activeOpacity={0.8}
      >
        <Text style={styles.selectedText}>
          {selectedItem ? selectedItem.label : placeholder}
        </Text>
        <Ionicons 
          name="chevron-down" 
          size={24} 
          color="#000" 
          style={styles.chevron} 
        />
      </TouchableOpacity>

      <Modal
        transparent={true}
        animationType="fade" 
        visible={modalVisible}
        onRequestClose={() => setModalVisible(false)}
      >
        <View style={styles.modalContainer}>
          <View style={styles.modal}>
            <FlatList
              data={items}
              keyExtractor={(item) => item.value.toString()}
              renderItem={({ item }) => (
                <TouchableOpacity
                  style={styles.item}
                  activeOpacity={0.8}
                  onPress={() => {
                    onValueChange(item.value);
                    setModalVisible(false);
                  }}
                >
                  <Text style={styles.itemText}>{item.label}</Text>
                </TouchableOpacity>
              )}
            />
          </View>
        </View>
      </Modal>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    marginBottom: 20,
  },
  dropdown: {
    flexDirection: 'row', 
    justifyContent: 'space-between',
    alignItems: 'center',
    padding: 12,
    backgroundColor: '#ffffff',
    borderRadius: 10,
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.3,
    shadowRadius: 3,
    elevation: 2, 
  },
  selectedText: {
    fontSize: 18,
    color: 'black',
  },
  chevron: {
    marginLeft: 10, 
  },
  modalContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    
  },
  modal: {
    width: '80%', 
    maxHeight: 300, 
    backgroundColor: 'white',
    borderRadius: 8,
    padding: 10,
    elevation: 4, 
    shadowColor: '#000', 
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.3,
    shadowRadius: 4,
  },
  item: {
    padding: 10,
  },
  itemText: {
    fontSize: 18,
  },
});

export default CustomDropdown;
