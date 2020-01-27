String voice; // voice değişkeni tanımlanıyor
int 
led1 = 2, //led'lerin bağlı olduğu pinler  
led2 = 3, 
led3 = 4, 
led4 = 5, 
led5 = 6; 
//--------------------------Fonksiyonların tanımlanması-------------------------------//  
void allon(){ // allon,hepsini aç fonksiyonu,tüm çıkışlar aktif
     digitalWrite(led1, HIGH); 
     digitalWrite(led2, HIGH); 
     digitalWrite(led3, HIGH); 
     digitalWrite(led4, HIGH); 
     digitalWrite(led5, HIGH); 
}
void alloff(){ //allof,hepsini kapa fonksiyonu,tğm çıkışlar pasif
     digitalWrite(led1, LOW); 
     digitalWrite(led2, LOW); 
     digitalWrite(led3, LOW); 
     digitalWrite(led4, LOW); 
     digitalWrite(led5, LOW);
}
//-----------------------------------------------------------------------//  
void setup() {
  Serial.begin(9600); // seri iletişim başlar
  pinMode(led1, OUTPUT); // led'ler çıkış elemanı
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT); 
}
//-----------------------------------------------------------------------//  
void loop() {
  while (Serial.available()){  //bilgi geldiği sürece
  delay(10); //güvenlik gecikmesi uygula
  char c = Serial.read(); //verileri oku c karekterine at
  if (c == '#') {break;} //# işareti gelirse,yani okuma bitmişse döngüyü durdur.
  voice += c; //gelen her karekteri ekle ve komut cümlesini tamamla
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 
//-----------------------------------------------------------------------//    
  //----------Tüm ledlerin kontrolü----------//  
       if(voice == "*all on") {allon();}  //all on denirse ledlerin hepsini aç
  else if(voice == "*all off"){alloff();} //all off denirse ledlerin hepsini kapa
  
  //----------Adım Adım Açma komutlar----------// 
  else if(voice == "*TV on") {digitalWrite(led1, HIGH);} //tv açma komutu
  else if(voice == "*fan on") {digitalWrite(led2, HIGH);} // fan çalıştırma komutu
  else if(voice == "*computer on") {digitalWrite(led3, HIGH);} // bilgisayar açma komutu
  else if(voice == "*bedroom lights on") {digitalWrite(led4, HIGH);} // yatak odası lambasını açma
  else if(voice == "*bathroom lights on") {digitalWrite(led5, HIGH);} // banyo lambasını açma
  //----------Adım Adım Kapatma komutları----------// 
  else if(voice == "*TV off") {digitalWrite(led1, LOW);} 
  else if(voice == "*fan off") {digitalWrite(led2, LOW);}
  else if(voice == "*computer off") {digitalWrite(led3, LOW);}
  else if(voice == "*bedroom lights off") {digitalWrite(led4, LOW);}
  else if(voice == "*bathroom lights off") {digitalWrite(led5, LOW);}
//-----------------------------------------------------------------------//  
voice="";}} //komutlar bitincce voice değişkenini sıfırla
