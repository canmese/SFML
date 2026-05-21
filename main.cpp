#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include <iostream>

int main() {
    // 1. PENCERE OLUŞTURMA
    // SFML 3.0'da boyutlar süslü parantez {} içinde sf::Vector2u olarak verilir.
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3.0 Test Penceresi");
    
    // Bilgisayarın fanını yormamak için FPS'i 60'a sabitliyoruz
    window.setFramerateLimit(60);

    // 2. OYUN DÖNGÜSÜ (Pencere açık kaldığı sürece çalışır)
    while (window.isOpen()) {
        
        // 3. OLAY (EVENT) KONTROLÜ
        // SFML 3.0'da olaylar std::optional ile kontrol edilir.
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            
            // Çarpı (X) tuşuna basılıp basılmadığını kontrol et
            if (event->is<sf::Event::Closed>()) {
                window.close(); // Pencereyi kapat
            }
        }

        // 4. EKRANI TEMİZLEME
        // Her kareden önce eski çizimleri temizleyip arka plan rengi atıyoruz.
        window.clear(sf::Color(50, 100, 150));

        // 5. ÇİZİMLERİ YAPMA
        // Eğer bir şekil (örneğin sf::CircleShape) çizmek isterseniz kodu buraya yazın:
        // window.draw(benimSeklim);

        // 6. EKRANI GÜNCELLEME
        // Arka planda hazırlanan çizimleri ekrana yansıt
        window.display();
    }

    return 0;
}
