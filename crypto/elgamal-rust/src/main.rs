use rand::rngs::StdRng;
use rand::SeedableRng;
use rust_elgamal::{DecryptionKey, Scalar, GENERATOR_TABLE};


fn main() {


    let mut rng = StdRng::from_entropy();
    let dec_key = DecryptionKey::new(&mut rng);

    println!("rng string {:?}",rng);
    println!("dec key {:?}",dec_key);

    {
	let enc_key = dec_key.encryption_key();

    
	let message = &Scalar::from(5u32) * &GENERATOR_TABLE;
	//#println!("message {:?}",message);
	let encrypted = enc_key.encrypt(message, &mut rng);

	//#println!("encrypted {:?}",encrypted);
	let decrypted = dec_key.decrypt(encrypted);
	assert_eq!(message, decrypted);

	println!("scalar {:?}", &Scalar::from(500000000u32));
		
    }

    {
    //#let message = Scalar::from(5u32);
    //#let enc_key = dec_key.encryption_key();

    //let encrypted = enc_key.encrypt(message);

    //let decrypted = dec_key.decrypt(encrypted);
    //println!("decrypted {:}",decrypted)
    //assert_eq!(message, decrypted);
    }
}
