//
//  HospitalContactsViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 2/7/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit
import Foundation

class HospitalContactsViewController: UIViewController {
    
    @IBOutlet weak var generalHospitalStatement: UILabel!
    
    @IBOutlet weak var generalHospitalInfo: UILabel!
    
    @IBOutlet weak var appointmentCardiologist: UILabel!
    @IBOutlet weak var cardiologyNurse: UILabel!
    @IBOutlet weak var medicationRefills: UILabel!
    
    @IBOutlet weak var faxNumberAuthorization: UILabel!
    
    @IBOutlet weak var afterHoursInfo: UILabel!
    
    @IBOutlet weak var faxNumberSurgery: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let hospitalStatement = "Your child's health is our priority. The Pediatric Cardiology is available form 8:00 a.m. to 5:00p.m. Monday through Thursday and 8:00 a.m. to 1:00 p.m. on Friday. Please feel free to contact us with any question or concerns regarding your child's cardiac condition."
        
        generalHospitalInfo.text = ""
        generalHospitalInfo.text =  "Phone number: (909) 558-4000"
        
        appointmentCardiologist.text = "Phone number: (909) 558-4207"
        
        faxNumberAuthorization.text = ""
        faxNumberAuthorization.text = "Phone number: (909) 558-0725"
        
        faxNumberSurgery.text = ""
        faxNumberSurgery.text = "Phone number: (909) 558-0311"
        
        generalHospitalStatement.text = ""
        generalHospitalStatement.text = hospitalStatement
        
        cardiologyNurse.text = ""
        cardiologyNurse.text = "Phone number: (909) 558-8138"
        
        medicationRefills.text = ""
        medicationRefills.text = "Phone number: (909) 558-8138"
        
        afterHoursInfo.text = ""
        afterHoursInfo.text = "During the weekends and after hours (5:00 p.m. - 8:00 a.m), a doctor is available FOR EMERGENCIES ONLY. Call Loma Linda Univeristy Medical Center at (909) 558-4000 and ask for the Pediatric Cardiologist on call."
        
        // Do any additional setup after loading the view.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
