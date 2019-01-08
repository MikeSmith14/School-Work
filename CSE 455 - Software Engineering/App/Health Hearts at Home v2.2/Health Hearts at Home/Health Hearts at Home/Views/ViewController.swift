//
//  ViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 2/7/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit


class ViewController: UIViewController {

    @IBOutlet weak var generalInfo: UIButton!
    @IBOutlet weak var tutorialsNeeds: UIButton!
    
    @IBOutlet weak var spiritualNeeds: UIButton!
    
    @IBOutlet weak var hospitalHelpline: UIButton!
    @IBOutlet weak var careGiver: UIButton!
    
    @IBOutlet weak var contacts: UIButton!
    
    @IBOutlet weak var trackChild: UIButton!
    
    @IBOutlet weak var aboutTreatment: UIButton!
    
    

    @IBAction func switchToSpanish(_ sender: UISwitch) {
        if(sender.isOn == true){
            generalInfo.setTitle("Información General de Cuidado Infantil", for: UIControlState.normal)
            tutorialsNeeds.setTitle("Tutoriales Para Cuidado Infantil", for: UIControlState.normal)
            spiritualNeeds.setTitle("Necesidades Espirituales", for: UIControlState.normal)
            hospitalHelpline.setTitle("Conexión al Hospital", for: UIControlState.normal)
            careGiver.setTitle("Apoyo del Cuidador", for: UIControlState.normal)
            contacts.setTitle("Contactos", for: UIControlState.normal)
            trackChild.setTitle("Sigue la Salud de Tu Hijo", for: UIControlState.normal)
            aboutTreatment.setTitle("Información Sobre TCC y Tratamiento", for: UIControlState.normal)
        }else{
            generalInfo.setTitle("General Child Care Information", for: UIControlState.normal)
            tutorialsNeeds.setTitle("Tutorials for Child Care Needs", for: UIControlState.normal)
            spiritualNeeds.setTitle("Spiritual Needs", for: UIControlState.normal)
            hospitalHelpline.setTitle("Hospital Helpline", for: UIControlState.normal)
            careGiver.setTitle("Care Giver Support", for: UIControlState.normal)
            contacts.setTitle("Contacts", for: UIControlState.normal)
            trackChild.setTitle("Track Your Child", for: UIControlState.normal)
            aboutTreatment.setTitle("About CHD and Treatment", for: UIControlState.normal)
        }
    }
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func homeScreenContacts(_ sender: Any) {
        performSegue(withIdentifier: "connectionCM", sender: self)
    }
    
}

