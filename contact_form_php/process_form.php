<?php
header('Content-Type: application/json');

// Array to hold errors
$errors = [];

// Validate Name
if (empty($_POST['name'])) {
  $errors['name'] = 'Name is required.';
} elseif (strlen($_POST['name']) < 3) {
  $errors['name'] = 'Name must be at least 3 characters long.';
}

// Validate Email
if (empty($_POST['email'])) {
  $errors['email'] = 'Email is required.';
} elseif (!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) {
  $errors['email'] = 'Invalid email format.';
}

// Validate Message
if (empty($_POST['message'])) {
  $errors['message'] = 'Message is required.';
} elseif (strlen($_POST['message']) < 10) {
  $errors['message'] = 'Message must be at least 10 characters long.';
}

// Check if there are any errors
if (!empty($errors)) {
  echo json_encode(['success' => false, 'errors' => $errors]);
} else {

  // If no errors, return success message
//   submit data to database
  echo json_encode(['success' => true]);

}
?>
