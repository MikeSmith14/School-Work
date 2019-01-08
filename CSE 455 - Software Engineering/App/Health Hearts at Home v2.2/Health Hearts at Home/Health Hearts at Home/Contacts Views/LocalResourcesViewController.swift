//
//  LocalResourcesViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 2/7/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit

class LocalResourcesViewController: UIViewController {

    @IBOutlet weak var resourceOneLabel: UILabel!
    @IBOutlet weak var resourceOneText: UILabel!
    @IBOutlet weak var resourceTwoLabel: UILabel!
    @IBOutlet weak var resourceTwoText: UILabel!
    @IBOutlet weak var resourceThreeLabel: UILabel!
    @IBOutlet weak var resourceThreeText: UILabel!
    @IBOutlet weak var resourceFourLabel: UILabel!
    @IBOutlet weak var resourceFourText: UILabel!
    @IBOutlet weak var resourceFiveLabel: UILabel!
    
    @IBOutlet weak var resourceFiveText: UILabel!
    
    @IBOutlet weak var resourceSixLabel: UILabel!
    @IBOutlet weak var resourceSixText: UILabel!
    
    @IBOutlet weak var resourceSevenLabel: UILabel!
    @IBOutlet weak var resourceSevenText: UILabel!
    
    
    //    override func viewDidLoad() {
//        super.viewDidLoad()
//
//        // Do any additional setup after loading the view.
//    }

    override func loadViewIfNeeded() {
        resourceOneLabel.text = "Healthy Families Program"
        resourceOneText.text = "The Healthy Families Program is a state "
        + "and federally health coverage program for children with family" +
        " incomes above the level eligible for no cost Medic- Cal. For more " +
        "information call 1-888-KIDS-NOW or call 1-888-747-1222 for Medi- Cali" +
        " for children and healthy Families General information."
        
        resourceTwoLabel.text = "Supplemental Security Income (SSI)"
        resourceTwoText.text = "SSI is a Federal income supplement program "
                                + "funded by general tax revenues. It is designed "
                                + "to help aged, blind and disabled people who have little or no "
                                + "income. It provides cash to meet basic needs for food, "
                                + "clothing and shelter."
    
        resourceThreeLabel.text = "California Children Services (CCS)"
        resourceThreeText.text = "CSS is a statewise program of specialized medical care and "
                                + "rehabilitation for handicapped children. CCS provides "
                                + "medical case management and financial assistance to "
                                + "children who meet CSS eligibility criteria. "
        
        resourceFourLabel.text = "211 San Bernardino Country (SBC)"
        resourceFourText.text = " 211 SBC is one stop connection to community services "
                                + "for those living in San Bernardino county through a "
                                + "troll-free 3-digit phone number, an online database and "
                                + "directory, and a 24 hour call center staffed by highly "
                                + "trained specialists.\n\n"
                                + "Dailing 2-1-1 is a cofidential call with live, bilingual "
                                + "staff to assist callers 24 hours a day. If you are outside "
                                + "the area or dialing 2-1-1 doesn't work at your place of "
                                + "business, you can always use 888-435-7565."
        
        resourceFiveLabel.text = "Regional Centers"
        resourceFiveText.text = "Regional centers provide Occupational, Physical and" + " Speech Therapy and other services to children who have"
            + " disabilities or who are at risk of delays due to medical"
            + " conditions. Services are free to families, regardless of"
            + " income or insurance."
            + " \n\nInland Regional Center: www.inlandrc.org"
            + "\nTelephone: (909) 890-3000"
        
        resourceSixLabel.text = "Camp Del Corazon"
        resourceSixText.text = "A free, nonprofit ACA accredited camp specializing"
            + " in children ages 7-17 years old with heart disease or"
            + " with a history of heart disease. This camp is held on"
            + " beautiful Catalina Island over Labor Day weekend."
            + "\n\nwww.campdelcorazon.org/"
        
        resourceSevenLabel.text = "Make A Wish"
        resourceSevenText.text = "Any child under the age of 18 with a life threatening" + " illness may be eligible for a wish. Wishes granted"
            + " include going on vacations, meeting professional athletes and"
            + " other celebrities, getting a computer, etc. The amazing things"
            + " provided by this organization are endless. Contact them to see"
            + " if yourchild is eligible to receive a wish. For more information"
            + " see www.makeawish.org or call (800) 722-9474"
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
