//
//  ExtraHandViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 3/13/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit
import Contacts

public var savedContact = [String]()
//public var saveOrderSource = [Any?]()
//public var saveOrderDestin = [Any?]()

class ExtraHandViewController: UIViewController, UITableViewDataSource, UITableViewDelegate{
    @IBOutlet weak var contactListTableView: UITableView!
    @IBOutlet weak var editButton: UIBarButtonItem!
    
    var contactStore = CNContactStore()
    var contactsList = [ContactStruct]()
    let contact = CNMutableContact()
    
    @IBAction func editButtonAction(_ sender: UIBarButtonItem) {
        contactListTableView.isEditing = !contactListTableView.isEditing
        if contactListTableView.isEditing{
            editButton.title = "Done"
        }else{
            editButton.title = "Edit"
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        contactsList.removeAll()
        contactListTableView.reloadData()
        self.viewDidLoad()
        editButton.title = "Edit"
        contactListTableView.delegate = self
        contactListTableView.dataSource =  self
        
        contactStore.requestAccess(for: .contacts){ (success, error) in
            if success{
                print("Authorization Successful")
            }
        }
        
        fetchSavedContacts()
    }
    
    func fetchSavedContacts(){
        print("In fetchSaveContacts")
        
        let key = [CNContactGivenNameKey, CNContactFamilyNameKey, CNContactPhoneNumbersKey,
                 CNContactJobTitleKey] as [CNKeyDescriptor]
        let request = CNContactFetchRequest(keysToFetch: key)

        savedContact = UserDefaults.standard.stringArray(forKey: "saveContact") ?? [String]()
        print(savedContact)
        
        var index = 0;
        var doesItExistInContacts = false;
        while(index < savedContact.count){
            try! contactStore.enumerateContacts(with: request){ (contact, stoppingPointer) in
                if(savedContact[index] == contact.givenName){
                    doesItExistInContacts = true;
                }
                if(doesItExistInContacts){
                    let firstName = contact.givenName
                    let lastName = contact.familyName
                    
                    var phoneNumber = ""
                    let contactNumberArray = contact.phoneNumbers
                    for contactNumber in contactNumberArray{
                        let number = contactNumber.value as CNPhoneNumber
                        phoneNumber = number.stringValue
                    }
                    
                    let contactToAppend = ContactStruct(name:       firstName, familyName: lastName, number: phoneNumber)
                    doesItExistInContacts = false
                    self.contactsList.append(contactToAppend)
                    self.contactListTableView.reloadData()
                }
            }
            index = index + 1
        }
        
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return contactsList.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = UITableViewCell(style: .subtitle, reuseIdentifier: nil)
        let contactToDisplay = contactsList[indexPath.row]
        cell.textLabel?.text = contactToDisplay.name + " " + contactToDisplay.familyName
        cell.detailTextLabel?.text = contactToDisplay.number
        return cell
    }
    
    func tableView(_ tableView: UITableView, canMoveRowAt indexPath: IndexPath) -> Bool {
        return true
    }
    
    func tableView(_ tableView: UITableView, moveRowAt sourceIndexPath: IndexPath, to destinationIndexPath: IndexPath) {
        let selectedItem = contactsList[sourceIndexPath.row]
        contactsList.remove(at: sourceIndexPath.row)
        contactsList.insert(selectedItem, at: destinationIndexPath.row)
        print(contactsList)
        savedContact = [String]()
        var index = 0;
        while( index < contactsList.count){
            savedContact.append(contactsList[index].name)
            index = index + 1
        }
        print(savedContact)
        UserDefaults.standard.set(savedContact, forKey: "saveContact")
        self.viewDidLoad()
    }
    
    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete{
            
            savedContact  = UserDefaults.standard.stringArray(forKey: "saveContact") ?? [String]()
            
            var index = 0
            while(index < savedContact.count){
                if(savedContact[index] == contactsList[indexPath.row].name){
                    savedContact.remove(at: index)
                }
                index = index + 1
            }
            UserDefaults.standard.set(savedContact, forKey: "saveContact")
            
            contactsList.remove(at: indexPath.row)
            contactListTableView.beginUpdates()
            contactListTableView.deleteRows(at: [indexPath], with: .automatic)
            contactListTableView.endUpdates()
        }
    }
    
    @IBAction func didUnwindFromAssistanceVC(_ sender: UIStoryboardSegue){
        guard let assistanceVC = sender.source as? AssistanceContactViewController else {return}
        
        print("IN didUnwindFromAssistanceVC")
        let firstname = assistanceVC.firstNameTextField.text
        let lastname = assistanceVC.lastNameTextField.text
        
        
//        let jobtitle = "CHD Extrahand"
        var doesItExistInContacts =  false;
        
        let key = [CNContactGivenNameKey, CNContactFamilyNameKey, CNContactPhoneNumbersKey, CNContactJobTitleKey] as [CNKeyDescriptor]
        let request = CNContactFetchRequest(keysToFetch: key)
        
        try! contactStore.enumerateContacts(with: request){
            (contact, stoppingPointer) in
            if(contact.givenName == firstname && contact.familyName == lastname && contact.jobTitle == "CHD Caregiver"){
                print("Yes it does exits in the iphone's contacts")
                doesItExistInContacts =  true;
            }
            
            if(doesItExistInContacts){
                var phoneNumber = ""
                
                let contactNumberArrary = contact.phoneNumbers
                for contactNumber in contactNumberArrary{
                    let number = contactNumber.value as CNPhoneNumber
                    phoneNumber = number.stringValue
                }
                
                savedContact = UserDefaults.standard.stringArray(forKey: "saveContact") ?? [String]()
                
                var index = 0
                var itExitsInSavedContact = false
                while(index < savedContact.count){
                    if(savedContact[index] == contact.givenName){
                        print("Yes it does exits in the savedContact Array")
                        itExitsInSavedContact = true;
                    }
                    index = index + 1
                }
                
                print(phoneNumber)
                if(itExitsInSavedContact == false){
                    print("Add the contact to the saveContact Array")
                    let appendToContactsList = ContactStruct(name: firstname!, familyName: lastname!, number: phoneNumber)
                    self.contactsList.append(appendToContactsList)
                    self.contactListTableView.reloadData()
                    savedContact.append(firstname!)
                    UserDefaults.standard.set(savedContact, forKey: "saveContact")
                }
                doesItExistInContacts = false
            }
            
        }
        

        
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
