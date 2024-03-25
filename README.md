# _**Embeded System Design with Ardunio**_

Bu reporsitory de ilk önce temel devre elemanları tanıyıp sonrada ardunio ile uygulamalarını göreceğiz. 

## _1- Voltage - Resistance - Current (Gerilim - Direnç - Akım)_

* Bir elektrik devresinin çalışabilmesi için gerilim kaynağına ihtiyaç duyarız. Bu priz, pil, akü,... olabilir. 
* Pillerde ve akülerde + ve - kısımları varken prizlerde yoktur.
* AA pil kalem pil iken AAA daha incedir. 
* Gerilimin birimi Volt (V) 'tur.
* Resistör (Direnç) 'ün yönü fark etmez. Birimi ohm (Ω) 'dur. 
* Direnç üzerinde renk kodları vardır. Bunlar büyüklüğü ölçmeye yarar. 
* Akımın oluşması için bir devrede gerilimin ve direncin olması lazım.
* Akımı ölçmek için ampermetre devreye seri bağlanır.
* Gerilim azalırsa akım azalır, artarsa artar. (Doğru orantı)
* Direnç azalırsa akım artar, artarsa azalır. (Ters orantı)

## _2- Voltage (Piller)_

* Bir çok gerilim kaynağı var; güneş pilleri, rüzgar tribünleri, doğalgaz santralleri, nükleer santraller, hidoelektirik santraller gibi...
* Pillerde ve akülerde elektrik depolanabilir.
* 9V pil: bağlantı yapılırken + ve - kısımları vardır. Ters bağlanırlırsa voltu -9V olarak ölçülür. Ardunio 9 Voltluk bir pille çalışabiliyor.
* Kalem pil: 1.5V'dur. + ve - kısımları vardır. Ters bağlandığında -1.5V olarak ölçülür. 2 tipi vardır: AA ve AAA. AAA, AA'ya göre daha incedir.
* Coin Battery: 3V'dur. Diğerleri gibi + ve - kısımları vardır.
* Güneş Pil: Peak Voltage ve Peak Current değerleri vardır. Bunlar bu pilden max alınabilecek değerlerdir. Ayrıca üstüne gelen ışık şiddeti de ayarlanabilmektedir.

## _3- Battery Connections (Pil Bağlantıları)_

* Farklı bir gerilime ihtiyaç duyarsak pil bağlantıları ile istediğimiz gerilimi elde edebiliriz.
  
  ![image](https://github.com/BusraYaydemir/EmbededSytemDesign-Ardunio/assets/147690122/bc3a0f23-a234-4c9b-b07b-219faa2ab6fb)


_**Neden Paralel Bağlantıda Volt Değişmezken (Gerilim artısı sağlanmazken) onu kullanmaya ihityaç duyarız?**_

Seri bağlantıda gerilim artar ama paralel bağlantıda gerilim artmaz. Onun yerine pilden sağlayabileceğimiz güç artar. Yani paralel bağlantıda sağlayabileceğimiz akım artıyor.

Mesela aynı piller ile yapılan seri ve paralel bağlı devrelerde seri bağlı olanla bir motoru çalıştırabilecek akımı sağlayamazken paralel bağlı devrede sağlayabiliriz.

## _4- Resistance (Direnç)_

* Direnç, elektrik akımına zorluk gösteren devre elemanıdır.
* Birimi ohm(Ω)'dur.
* Üstündeki renklerden kaç Ω olduğu anlaşılmaktadır.

![Add a subheading](https://github.com/BusraYaydemir/EmbededSytemDesign-Ardunio/assets/147690122/77d642a1-31a3-4aa0-af9d-0e0f7e419f7b)

![Add a subheading (1)](https://github.com/BusraYaydemir/EmbededSytemDesign-Ardunio/assets/147690122/e5fba61d-d63d-4e62-867e-771c4320bf74)
