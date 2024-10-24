function toggleMenu() {
  const menu = document.querySelector(".menu-links");
  const icon = document.querySelector(".hamburger-icon");
  menu.classList.toggle("open");
  icon.classList.toggle("open");
}

var typed = new Typed('#element', {
  strings: ['<i>First</i> sentence.', '&amp; a second sentence.'],
  typeSpeed: 50,
});