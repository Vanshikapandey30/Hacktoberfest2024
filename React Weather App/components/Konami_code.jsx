import React, { useEffect, useState } from 'react';
import { motion } from 'framer-motion';
import Confetti from 'react-confetti';
import '../public/css/KonamiCode.css';

const KonamiCode = () => {
    const [konamiCodeEntered, setKonamiCodeEntered] = useState(false);
    const [windowSize, setWindowSize] = useState({ width: window.innerWidth, height: window.innerHeight });

    useEffect(() => {
        const konamiCode = [
            'ArrowUp', 'ArrowUp', 'ArrowDown', 'ArrowDown', 
            'ArrowLeft', 'ArrowRight', 'ArrowLeft', 'ArrowRight', 'b', 'a'
        ];
        let konamiCodeIndex = 0;

        const handleKeyDown = (event) => {
            if (event.key === konamiCode[konamiCodeIndex]) {
                konamiCodeIndex++;
                if (konamiCodeIndex === konamiCode.length) {
                    setKonamiCodeEntered(true);
                }
            } else {
                konamiCodeIndex = 0;
            }
        };

        window.addEventListener('keydown', handleKeyDown);

        // Mettre à jour la taille de la fenêtre pour les confettis
        const handleResize = () => {
            setWindowSize({ width: window.innerWidth, height: window.innerHeight });
        };
        window.addEventListener('resize', handleResize);

        return () => {
            window.removeEventListener('keydown', handleKeyDown);
            window.removeEventListener('resize', handleResize);
        };
    }, []);

    return (
        <div className="konami-container">
            {konamiCodeEntered ? (
                <>
                    {/* Effet confettis */}
                    <Confetti
                        width={windowSize.width}
                        height={windowSize.height}
                        numberOfPieces={500}
                        recycle={false} // Confettis arrêtent après un certain temps
                    />
                    {/* Animation avec Framer Motion après avoir entré le code Konami */}
                    <motion.h1
                        initial={{ opacity: 0, scale: 0.5, rotate: -180 }}
                        animate={{ opacity: 1, scale: [1.5, 1], rotate: 0 }}
                        transition={{ duration: 0.8, ease: 'easeOut', bounce: 0.3 }}
                        className="konami-text"
                    >
                        Konami Code Entered!
                    </motion.h1>
                </>
            ) : (
                // Affichage initial sans animation
                <h1 className="konami-text">
                </h1>
            )}
        </div>
    );
};

export default KonamiCode;
